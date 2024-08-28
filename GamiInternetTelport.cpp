#include "GamiInternetTelport.h"
#include <stdio.h>
#include <string.h>
#include <QApplication>
#include <QKeyEvent>
#include <QEvent>

#include <QScreen>
#include <QDebug>
#include <QBuffer>
#include <QPixmap>
#include <pair.h>
#include <bus.h>
#include <nn.h>


#ifndef WIN32
#include <assert.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

bool saveImageToBuffer(const QImage &image, QBuffer &buffer, int quality = -1);
bool saveImageToBuffer(const QImage &image, QBuffer &buffer, int quality) {
    buffer.open(QIODevice::WriteOnly);
    bool success = image.save(&buffer, "JPG", quality);
    return success;
}
GamiInternetTelport::GamiInternetTelport():_canvas_sockfd(-1),_key_seq( 1),_last_receive_seq( 0){
    _canvas_sockfd = nn_socket(AF_SP, NN_BUS);
    _key_sockfd = nn_socket(AF_SP, NN_PAIR);
    _thread = new GamiInternetTelportThread;
    _thread->start();
    setSenderMode(false);
    qRegisterMetaType<stKey>("stKey");

    connect(this, SIGNAL(signal_frame_key(stKey * )), this ,SLOT(OnKey(stKey * )), Qt::QueuedConnection);
    connect(_thread, SIGNAL(signal_thread_run()), this ,SLOT(thread()),Qt::DirectConnection);


#ifndef WIN32
    _file.setFileName("/dev/fb0");
    if(!_file.open(    QFile::ReadOnly)){
        return;
    }
    struct fb_var_screeninfo vinfo;
    if(ioctl(_file.handle(), FBIOGET_VSCREENINFO, &vinfo)){
       _file.close();
       return;
    }

    int w = vinfo.xres;
    int h = vinfo.yres;
    int screensize = w * h* vinfo.bits_per_pixel / 8;

    _screen_size = screensize;
    _screen_w = w;
    _screen_h = h;
#endif



}
GamiInternetTelport::~GamiInternetTelport(){
    _key_thread_running.store(false);
}
void GamiInternetTelport::sendKey(stKey e){
    e.seq = _key_seq;
    nn_send(_key_sockfd, &e , sizeof(e), 0);
    _key_seq++;
}
void GamiInternetTelport::sendBuffer(QImage &canvas){
    QBuffer buffer;
    saveImageToBuffer(canvas, buffer , 20);
    nn_send(_canvas_sockfd , buffer.data(), buffer.size(), 0);
    buffer.close();
}
void GamiInternetTelport::setSenderMode(bool val){
    _is_sender = val;
}

bool GamiInternetTelport::isSender()
{
    return _is_sender;
}
bool GamiInternetTelport::bindServer(const char *ip, unsigned short port){
    char addr[128] = { 0};
    sprintf(addr, "tcp://%s:%d", ip , port);

    if(nn_bind(_canvas_sockfd , addr) < 0)
        return false;
    sprintf(addr, "tcp://%s:%d", ip , port+1);
    if(nn_bind(_key_sockfd , addr) < 0)
        return false;

    connect(&_default_timer, SIGNAL(timeout()) , this ,SLOT(defaultTimeout()));
    _default_timer.start(16);
    return true;
}
bool GamiInternetTelport::connectToServer(const char *ip, unsigned short port){
    char addr[128] = { 0};
    sprintf(addr, "tcp://%s:%d", ip , port);
    if(nn_connect(_canvas_sockfd , addr) < 0)
        return false;
    sprintf(addr, "tcp://%s:%d", ip , port+1);
    if(nn_connect(_key_sockfd , addr) < 0)
        return false;

    connect(&_default_timer, SIGNAL(timeout()) , this ,SLOT(defaultTimeout()));
    _default_timer.start(16);
    return true;
}
void GamiInternetTelport::exec(){
    if(_is_sender){
       getScreen(_canvas);
       sendBuffer(_canvas);
    }

    struct nn_pollfd fd[1] = { 0};
    fd[0].fd =  _canvas_sockfd;
    fd[0].events = NN_POLLIN;
    int timeout = 1; // 超时时间，单位为毫秒
    int rc = nn_poll(fd, 1, timeout);
    if (rc < 0) {
    } else if (rc == 0) {
    } else {
            if (fd[0].revents & NN_POLLIN) {
                char *buffer;
                int sockfd =  _canvas_sockfd;
                int length = nn_recv(sockfd , &buffer, NN_MSG, 0);
                QByteArray array(buffer, length);


                if(!_is_sender)
                   emit signal_frame_update(array);

                nn_freemsg(buffer);
            }
    }
}
void GamiInternetTelport::getScreen(QImage &canvas){
#ifdef WIN32
    QScreen *screen = QApplication::primaryScreen();
    if (screen)
        canvas=  screen->grabWindow(0).toImage();
#else

    image = QImage(_screen_w,_screen_h,QImage::Format_RGB32);
    image.fill(Qt::red);

    QPainter painter(&image);
    painter.setPen(QPen(Qt::white, 2));
    QFont font = painter.font();
    font.setPixelSize(30);
    painter.drawText(0,0,_screen_w, _screen_h,Qt::AlignCenter,"HELLO!");
    return;
    qDebug() << "framebuffer size | "<< "w = " << _screen_w << ", h = " <<  _screen_h<<", size = " << _screen_size;

    static unsigned char *fb_ptr = (unsigned char *)mmap(NULL, _screen_size, PROT_READ, MAP_SHARED, _file.handle(),0 );

    if(!fb_ptr){
        qDebug()<<"fp_ptr is nullptr";
        image = QImage(_screen_w, _screen_h,      QImage::Format_RGB32);
        return;
    }
    image = QImage(fb_ptr, _screen_w, _screen_h,      QImage::Format_RGB32);
#endif
}

void GamiInternetTelport::thread(){
    _key_thread_running.store(true);
    while(_key_thread_running.load()){
        QMutexLocker m(&_key_mutex);
        for(int i = 0; i < 1; i++){
            if(!_key_queue_sender_container.isEmpty()){
               auto key = _key_queue_sender_container.first();
               sendKey(key);

               _key_queue_sender_container.pop_front();
            }else
                break;
        }

        struct nn_pollfd fd[1] = { 0};
        fd[0].fd =  _key_sockfd;
        fd[0].events = NN_POLLIN;
        int timeout = 16; // 超时时间，单位为毫秒
        int rc = nn_poll(fd, 1, timeout);
        if (rc < 0) {
        } else if (rc == 0) {
        } else {
                if (fd[0].revents & NN_POLLIN) {
                    char *buffer;
                    int sockfd =  _key_sockfd;
                    int length = nn_recv(sockfd , &buffer, NN_MSG, 0);
                    QByteArray array(buffer, length);
#if 0
                    stKey key = *(stKey * ) buffer;

                    QKeyEvent *keyevent = new QKeyEvent(key.type, key.key,
                                                        Qt::KeyboardModifier::NoModifier,QString(),
                                                        key.reauto, key.count);
#endif

                    stKey *key =new stKey;

                    if(key->seq == _key_seq)
                        return;
                    _last_receive_seq = _key_seq;

                    memcpy(key, buffer ,sizeof(stKey));
                    emit signal_frame_key(key);
                    nn_freemsg(buffer);
                }
        }


    }

    nn_close(_key_sockfd);
}
void GamiInternetTelport::defaultTimeout(){
    exec();
}
void GamiInternetTelport::OnKey(stKey* e){
    if(!_is_sender){
#if 0
        auto keyevent= ((QKeyEvent *)e);
        stKey key;
        key.key = (Qt::Key)keyevent->key();
        key.type = e->type();
        key.reauto = keyevent->isAutoRepeat();
        key.count = keyevent->count();
        key.type = e->type();
#endif
        _key_mutex.lock();
        _key_queue_sender_container.push_back( *e);
        _key_mutex.unlock();
    }
    else{
#if 0
       QKeyEvent *e = new QKeyEvent(type, key, Qt::KeyboardModifier::NoModifier);

#endif
#if 0
       QKeyEvent *keyevent= ((QKeyEvent *)e);
       auto obj = (QObject *)QApplication::focusWidget();
       if(obj)
          QApplication::sendEvent(obj, keyevent);
#endif

       stKey &key = *e;

       QKeyEvent keye(key.type, key.key,
                                           Qt::KeyboardModifier::NoModifier,QString(),
                                           key.long_press, key.count);
       auto obj = (QObject *)QApplication::focusWidget();
       if(obj)
          QApplication::sendEvent(obj, &keye);

       qDebug() << obj << Qt::Key(keye.key());

       delete e;

    }
}

GamiInternetTelportThread::GamiInternetTelportThread(){}
GamiInternetTelportThread::~GamiInternetTelportThread(){}

void GamiInternetTelportThread::run(){
    emit signal_thread_run();
}
