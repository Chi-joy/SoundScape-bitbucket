/**

@file main.cpp
@brief The main entry point for the SoundScape application.
The SoundScape application provides a platform for music enthusiasts to discover new music based on their current location.
The application uses the Spotify API to retrieve the user's playlists and the Google Geolocation API to determine the user's current location.
@author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
*/

#include "GoogleAPI.h"
#include "loginwindow.h"
#include "timer.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>
#include <QThread>
#include "QtCore/qtimer.h"

/**

@brief The main function that runs the SoundScape application.
This function initializes the application, loads translations, creates and shows the LoginWindow, and starts the event loop.
@param argc The number of command-line arguments.
@param argv The array of command-line arguments.
@returns An integer value that indicates the exit status of the application.
*/
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


    return a.exec();
}
