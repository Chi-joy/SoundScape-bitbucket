#include <string>
#include <iostream>
#include <vector>

#ifndef PLAYLIST_H   // To make sure you don't declare the function more than once by including the header multiple times.
#define PLAYLIST_H

namespace Playlist {
    
    class playlist {

    private:
        std::string playlistName;
        std::string playlistURI;
        std::string playlistCoverURI;
        //std::vector<Song::song> sVector;
        bool hasLocation;

    public:
        playlist();
        playlist(std::string playlistName, std::string playlistURL, std::string playlistCoverURI, bool hasLocation);
        ~playlist();
        std::string getPlaylistName();
        std::string getPlaylistURI();
        std::string getPlaylistCoverURI();

        void setPlaylistName(std::string newName);
        void setPlaylistURI(std::string songURI);
        void setPlaylistCoverURI(std::string songArtist);
        // bool hasSong(std::string songURI);
        // bool isPlaying(std::string songURI);
        // Song::song getSong(std::string songURI);
    };

    
}

#endif
