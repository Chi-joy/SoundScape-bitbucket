#include <string>
#include <iostream>
#include <vector>
#include "Song.h"

namespace Playlist {
    
    class playlist {

    private:
        std::string playlistName;
        std::string playlistURI;
        std::string playlistCoverURI;
        std::vector<Song::song> songVector;
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
