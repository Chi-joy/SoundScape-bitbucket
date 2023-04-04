#include "GoogleAPI.h"
#include "loginwindow.h"
#include "timer.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>
#include <QThread>
#include "QtCore/qtimer.h"

//class MyClass : public QObject {
//    Q_OBJECT
//public:
//    MyClass(QObject *parent = nullptr) : QObject(parent) {
//        pingingBackground ping;
//        QTimer * timer = new QTimer(this);
//        QObject::connect(timer, &QTimer::timeout, &ping, &pingingBackground::pingLocation);
//        timer->start(1000);
//    }
//};




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "SoundScape_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    LoginWindow w;
    w.show();


//    pingingBackground ping;
//    QTimer timer;
//    QObject::connect(&timer, &QTimer::timeout, &ping, &pingingBackground::pingLocation);
//    timer.start(1000);


    return a.exec();
}
