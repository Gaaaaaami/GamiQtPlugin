#include "GamiInternetTelportDisplay.h"
#include "GamiInternetTelport.h"
#include "ui_GamiInternetTelportDisplay.h"
#include <QPainter>
#include <QDebug>
#include <QBuffer>
#include <QImage>
bool bufferToImage(QBuffer &buffer, QImage &image);
bool bufferToImage(QBuffer &buffer, QImage &image) {
    // 先确保 QBuffer 已经打开并且读取模式可用
    buffer.open(QIODevice::WriteOnly);


    // 从 QBuffer 读取数据
    QByteArray data = buffer.data();

    // 创建 QImage 从字节数组
    QImage tempImage;
    if (tempImage.loadFromData(data)) {
        image = tempImage;
        buffer.close();
        return true;
    } else {
        qDebug() << "Failed to load image from buffer data!";
        buffer.close();
        return false;
    }
    buffer.close();
}
GamiInternetTelportDisplay::GamiInternetTelportDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamiInternetTelportDisplay),_canvas(width(),height(), QImage::Format_RGB16){
    ui->setupUi(this);
}
GamiInternetTelportDisplay::~GamiInternetTelportDisplay(){
    delete ui;
}

void GamiInternetTelportDisplay::bindInternetTelport(GamiInternetTelport *p){
    _internet_telport = p;
}
void GamiInternetTelportDisplay::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawImage(0,0,_canvas.scaled(width(),height()));
}
void GamiInternetTelportDisplay::OnFrameUpdate(QByteArray data){
    QBuffer buffer(&data);
    QImage  backg;
    bufferToImage(buffer ,_canvas );
    this->update();
}
void GamiInternetTelportDisplay::keyPressEvent(QKeyEvent *e){
    qDebug() << e;
    auto keyevent= ((QKeyEvent *)e);
    GamiInternetTelport::stKey key;
    key.key = (Qt::Key)keyevent->key();
    key.type = e->type();
    key.long_press = keyevent->isAutoRepeat();
    key.count = keyevent->count();
    key.type = e->type();

    if(_internet_telport)
        if(!_internet_telport->isSender())
            emit _internet_telport->signal_frame_key(&key);
}
void GamiInternetTelportDisplay::keyReleaseEvent(QKeyEvent *e){
    qDebug() << e;
    auto keyevent= ((QKeyEvent *)e);
    GamiInternetTelport::stKey key;
    key.key = (Qt::Key)keyevent->key();
    key.type = e->type();
    key.long_press = keyevent->isAutoRepeat();
    key.count = keyevent->count();
    key.type = e->type();
    if(_internet_telport)
        if(!_internet_telport->isSender())
            emit _internet_telport->signal_frame_key(&key);

}
