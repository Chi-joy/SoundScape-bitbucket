#include "GoogleAPI.h"
#include "loginwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>
#include <QThread>




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

        // Wait for some time...
    //QThread::sleep(10); // Sleep for 10 seconds

        // Stop the thread and wait for it to finish
    //thread.stop();


    return a.exec();
}
