/**
 * @file playlist.cpp
 * @brief Implementation of the playlist class.
 * 
 * This file contains the implementation of the playlist class, which
 * holds a playlist.
 * 
 * @author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
 */

#include "playlist.h"

using namespace Playlist;

/**
 * @brief Constructs a new playlist object.
 * 
 * This constructor creates a new playlist object with no parameters.
 * It is the default.
 */
playlist::playlist()
{
    std::cout << "default contructor. please enter parameters" << std::endl;
}

/**
 * @brief Constructs a new playlist object.
 * 
 * This constructor creates a new playlist object with the given song name, song URI, and song artist.
 * 
 * @param playlistName Name of the playlist.
 * @param playlistURI Identifier for the playlist.
 * @param playlistCoverURI Identifier for the playlist cover.
 * @param hasLocation If the playlist has a location associated with it.
 */
playlist::playlist(QString playlistName, QString playlistURI, QString playlistCoverURI, bool hasLocation)
{
    this->playlistName = playlistName;
    this->playlistURI = playlistURI;
    this->playlistCoverURI = playlistCoverURI;
    this->hasLocation = hasLocation;
}

/**
 * @brief Gets a playlist name.
 * 
 * @return A playlist name
 */
QString playlist::getPlaylistName() {
    return playlistName;
}

/**
 * @brief Gets a playlist identifier.
 * 
 * @return A playlist identifier.
 */
QString playlist::getPlaylistURI() {
    return playlistURI;
}

/**
 * @brief Gets a playlist cover identifier.
 * 
 * @return A playlist cover identifier.
 */
QString playlist::getPlaylistCoverURI() {
    return playlistCoverURI;
}

/**
 * @brief Sets a playlist name.
 * 
 * @param newName The new playlist name.
 */
void playlist::setPlaylistName(QString newName) {
    playlistName = newName;
}

/**
 * @brief Sets a playlist identifier.
 * 
 * @param newURI The new playlist identifier.
 */
void playlist::setPlaylistURI(QString newURI) {
    playlistURI = newURI;
}

/**
 * @brief Sets a playlist cover identifier.
 * 
 * @param newCoverURI The new playlist cover identifier.
 */
void playlist::setPlaylistCoverURI(QString newCoverURI) {
        playlistCoverURI = newCoverURI;
}


