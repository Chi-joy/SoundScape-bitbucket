#include "song.h"

using namespace Song;

song::song() {
    //default
}
song::song(std::string songName, std::string songURI, std::string songArtist) {
    songName = songName;
    songURI = songURI;
    songArtist = songArtist;
}
song::~song() {
    //
}

std::string song::getSongName() {
    return songName;
}
std::string song::getSongURI() {
    return songURI;
}
std::string song::getSongArtist() {
    return songArtist;
}
void song::setSongName(std::string newName) {
    songName = newName;
}
void song::setSongURI(std::string songURI) {
    songURI = songURI;
}
void song::setSongArtist(std::string songArtist) {
    songArtist = songArtist;
}
