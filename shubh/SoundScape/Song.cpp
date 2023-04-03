#include "Song.h"

using namespace Song;

song::song() {
    //default
}
song::song(QString songName, QString songURI, QString songArtist) {
    this->songName = songName;
    this->songURI = songURI;
    this->songArtist = songArtist;
}
song::~song() {
    //
}

QString song::getSongName() {
    return songName;
}
QString song::getSongURI() {
    return songURI;
}
QString song::getSongArtist() {
    return songArtist;
}
void song::setSongName(QString newName) {
    songName = newName;
}
void song::setSongURI(QString songURI) {
    this->songURI = songURI;
}
void song::setSongArtist(QString songArtist) {
    this->songArtist = songArtist;
}
