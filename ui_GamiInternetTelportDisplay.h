/********************************************************************************
** Form generated from reading UI file 'GamiInternetTelportDisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMIINTERNETTELPORTDISPLAY_H
#define UI_GAMIINTERNETTELPORTDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamiInternetTelportDisplay
{
public:
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *GamiInternetTelportDisplay)
    {
        if (GamiInternetTelportDisplay->objectName().isEmpty())
            GamiInternetTelportDisplay->setObjectName(QString::fromUtf8("GamiInternetTelportDisplay"));
        GamiInternetTelportDisplay->resize(1024, 768);
        horizontalLayout = new QHBoxLayout(GamiInternetTelportDisplay);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        retranslateUi(GamiInternetTelportDisplay);

        QMetaObject::connectSlotsByName(GamiInternetTelportDisplay);
    } // setupUi

    void retranslateUi(QWidget *GamiInternetTelportDisplay)
    {
        GamiInternetTelportDisplay->setWindowTitle(QCoreApplication::translate("GamiInternetTelportDisplay", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GamiInternetTelportDisplay: public Ui_GamiInternetTelportDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMIINTERNETTELPORTDISPLAY_H
