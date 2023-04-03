#include "QtCore/qstring.h"
#include <string>
#include <iostream>
#include <vector>

#ifndef SONG_H   // To make sure you don't declare the function more than once by including the header multiple times.
#define SONG_H

namespace Song {
    
    class song {

    private:
        QString songName;
        QString songURI;
        QString songArtist;

    public:
        song();
        song(QString songName, QString songURI, QString songArtist);
        ~song();
        QString getSongName();
        QString getSongURI();
        QString getSongArtist();

        void setSongName(QString newName);
        void setSongURI(QString songURI);
        void setSongArtist(QString songArtist);
    };
    
}

#endif
