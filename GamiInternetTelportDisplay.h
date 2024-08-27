#ifndef GAMIINTERNETTELPORTDISPLAY_H
#define GAMIINTERNETTELPORTDISPLAY_H

#include <QWidget>
#include <QPaintEvent>
#include <QKeyEvent>
namespace Ui {
class GamiInternetTelportDisplay;
}
class GamiInternetTelport;
class GamiInternetTelportDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit GamiInternetTelportDisplay(QWidget *parent = nullptr);
    ~GamiInternetTelportDisplay();
public:
    void bindInternetTelport(GamiInternetTelport *p);
private:
    virtual void paintEvent(QPaintEvent *event) override;
protected slots:
    void OnFrameUpdate(QByteArray data);
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
private:
    Ui::GamiInternetTelportDisplay *ui;
private:
    QImage                       _canvas;
private:
    GamiInternetTelport         *_internet_telport;
};

#endif // GAMIINTERNETTELPORTDISPLAY_H
