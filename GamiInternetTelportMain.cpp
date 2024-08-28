#include <QApplication>
#include <QDebug>
#include <iostream>
#include <string>
#include "GamiInternetTelport.h"
#include "GamiInternetTelportDisplay.h"

std::string getParamter(std::string paramter , int argc, char *argv[]){
    for(int i = 0; i < argc ; i++){
        if(std::string(argv[i]) == paramter && (i+1) < argc){
            return std::string(argv[i+1]);
        }
    }
    return std::string();
}
void InitGamiInternetTelport(int argc, char *argv[]){
    std::string mode = getParamter("-mode", argc , argv);
    std::string ip = getParamter("-ip", argc , argv);
    std::string port = getParamter("-port", argc , argv);

    if(ip == "")
       ip = "127.0.0.1";
    if(port == "")
       port = "85556";
    static GamiInternetTelport internet_telport;
    static GamiInternetTelportDisplay internet_telport_display;
    internet_telport_display.bindInternetTelport(&internet_telport);
    if(mode == "" || mode == "sender"){
       internet_telport.bindServer( ip.c_str(), atoi(port.c_str()));
       internet_telport.setSenderMode(true);
    }
    else if(mode == "receive"){
        internet_telport.setSenderMode(false);
        internet_telport.connectToServer(ip.c_str(), atoi(port.c_str()));
        QObject::connect(&internet_telport, SIGNAL(signal_frame_update(QByteArray)), &internet_telport_display,
                         SLOT(OnFrameUpdate(QByteArray)));
        internet_telport_display.show();
    }
}

#ifndef GAMI_CONTROLLER_NO_MAIN
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InitGamiInternetTelport(argc, argv);
    return a.exec();
}
#endif
