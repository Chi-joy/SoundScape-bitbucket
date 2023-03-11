#include <string>
#include <iostream>
#include <vector>

namespace Song {
    
    class song {

    private:
        std::string songName;
        std::string songURI;
        std::string songArtist;

    public:
        song();
        song(std::string songName, std::string songURI, std::string songArtist);
        ~song();
        std::string getSongName();
        std::string getSongURI();
        std::string getSongArtist();

        void setSongName(std::string newName);
        void setSongURI(std::string songURI);
        void setSongArtist(std::string songArtist);
    };
    
}