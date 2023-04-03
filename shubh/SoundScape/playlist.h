
#include "Song.h"

#ifndef PLAYLIST_H   // To make sure you don't declare the function more than once by including the header multiple times.
#define PLAYLIST_H

namespace Playlist {
    
    class playlist {

    private:
        QString playlistName;
        QString playlistURI;
        QString playlistCoverURI;
        //std::vector<Song::song> sVector;
        bool hasLocation;

    public:
        playlist();
        playlist(QString playlistName, QString playlistURL, QString playlistCoverURI, bool hasLocation);
        QString getPlaylistName();
        QString getPlaylistURI();
        QString getPlaylistCoverURI();

        void setPlaylistName(QString newName);
        void setPlaylistURI(QString songURI);
        void setPlaylistCoverURI(QString songArtist);
        // bool hasSong(QString songURI);
        // bool isPlaying(QString songURI);
        // Song::song getSong(QString songURI);
    };

    
}

#endif
