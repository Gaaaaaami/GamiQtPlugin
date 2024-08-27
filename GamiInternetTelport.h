#ifndef GAMIINTERNETTELPORT_H
#define GAMIINTERNETTELPORT_H

#include <QImage>
#include <QObject>
#include <QTimer>
#include <QByteArray>
#include <QKeyEvent>
#include <QQueue>
#include <QEvent>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
class GamiInternetTelportThread:public QThread{
    Q_OBJECT
public:
    GamiInternetTelportThread();
    virtual ~GamiInternetTelportThread();
protected:
    virtual void run() override;
signals:
    void signal_thread_run();

};
class GamiInternetTelport:public QObject
{
    Q_OBJECT
public:
    typedef struct {
        unsigned char seq;
        Qt::Key key;
        QEvent::Type type;
        bool long_press;
        int count;
    }stKey;
public:
    GamiInternetTelport();
    virtual ~GamiInternetTelport();
public:
    void sendKey(stKey e);
    void sendBuffer(QImage &canvas);
    void setSenderMode(bool );
public:
    bool isSender();
public:
    virtual bool bindServer(const char *ip , unsigned short port );
    virtual bool connectToServer(const char *ip, unsigned short port);
    virtual void exec();
signals:
    void signal_frame_update(QByteArray);
    void signal_frame_key(stKey *e);
protected:
    virtual void getScreen(QImage & canvas);
protected slots:
    virtual void thread();
    virtual void defaultTimeout();
    virtual void OnKey(stKey *e);
private:
    int                     _canvas_sockfd;
    int                     _key_sockfd;
private:
    QMutex                  _key_mutex;
private:
    QImage                  _canvas;
    QTimer                  _default_timer;
private:
    bool                    _is_sender;
private:
    QQueue<stKey>           _key_queue_sender_container;
private:
    GamiInternetTelportThread   *_thread;
private:
    unsigned char               _key_seq;
    unsigned char               _last_receive_seq;
};

#endif // GAMIINTERNETTELPORT_H
