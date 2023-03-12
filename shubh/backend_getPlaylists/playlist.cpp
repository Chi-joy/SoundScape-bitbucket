#include "playlist.h"
#include "song.h"

using namespace Playlist;

playlist::playlist()
{
    std::cout << "default contructor. please enter parameters" << std::endl;
}

playlist::playlist(std::string playlistName, std::string playlistURL, std::string playlistCoverURI, bool hasLocation)
{
    playlistName = playlistName;
    playlistURL = playlistURL;
    playlistCoverURI = playlistCoverURI;
    hasLocation = hasLocation;

    //we need a api call to get the song list and set the song vector (if we even need the songs??)
}

playlist::~playlist()
{
}

std::string playlist::getPlaylistName() {
    return playlistName;
}
std::string playlist::getPlaylistURI() {
    return playlistURI;
}
std::string playlist::getPlaylistCoverURI() {
    return playlistCoverURI;
}

void playlist::setPlaylistName(std::string newName) {
    playlistName = newName;
}
void playlist::setPlaylistURI(std::string newURI) {
    playlistURI = newURI;
}
void playlist::setPlaylistCoverURI(std::string newCoverURI) {
        playlistCoverURI = newCoverURI;
}

/*
commenting out the song methods since they need the api delegate set up


// bool playlist::hasSong(std::string songURI) {
//     //iterate through song vector, using getSongURI()
//     //return match if found
//     //false if else
// }

// Song::song playlist::getSong(std::string songURI) {
//     //iterate through song vector, using getSongURI()
//     //return match if found
//     //false if else
// }

// somearray playlist::getSongURIs() {
//     //iterate through song vector
//     //save .getSongURI() response in array
//     //return array 

// }

// bool playlist::isPlaying(std::string songURI) {
//     //call to spotify api delegate and return response
// }

*/

