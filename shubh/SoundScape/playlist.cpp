#include "playlist.h"

using namespace Playlist;

playlist::playlist()
{
    std::cout << "default contructor. please enter parameters" << std::endl;
}

playlist::playlist(QString playlistName, QString playlistURI, QString playlistCoverURI, bool hasLocation)
{
    this->playlistName = playlistName;
    this->playlistURI = playlistURI;
    this->playlistCoverURI = playlistCoverURI;
    this->hasLocation = hasLocation;

    //we need a api call to get the song list and set the song vector (if we even need the songs??)
}

QString playlist::getPlaylistName() {
    return playlistName;
}
QString playlist::getPlaylistURI() {
    return playlistURI;
}
QString playlist::getPlaylistCoverURI() {
    return playlistCoverURI;
}

void playlist::setPlaylistName(QString newName) {
    playlistName = newName;
}
void playlist::setPlaylistURI(QString newURI) {
    playlistURI = newURI;
}
void playlist::setPlaylistCoverURI(QString newCoverURI) {
        playlistCoverURI = newCoverURI;
}

/*
commenting out the song methods since they need the api delegate set up


// bool playlist::hasSong(QString songURI) {
//     //iterate through song vector, using getSongURI()
//     //return match if found
//     //false if else
// }

// Song::song playlist::getSong(QString songURI) {
//     //iterate through song vector, using getSongURI()
//     //return match if found
//     //false if else
// }

// somearray playlist::getSongURIs() {
//     //iterate through song vector
//     //save .getSongURI() response in array
//     //return array

// }

// bool playlist::isPlaying(QString songURI) {
//     //call to spotify api delegate and return response
// }

*/

