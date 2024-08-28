SOURCES += \
        GamiInternetTelport.cpp \
        GamiInternetTelportDisplay.cpp \
        GamiInternetTelportMain.cpp

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/include/nanomsg

LIBS += -L$$PWD/lib -lnanomsg

HEADERS += \
    GamiInternetTelport.h \
    GamiInternetTelportDisplay.h

FORMS += \
    GamiInternetTelportDisplay.ui
