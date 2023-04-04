/**
 * @file Song.cpp
 * @brief Implementation of the song class.
 * 
 * This file contains the implementation of the song class, which
 * holds a song.
 * 
 * @author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
 */

#include "Song.h"

using namespace Song;

/**
 * @brief Constructs a new Song object.
 * 
 * This constructor creates a new Song object with no parameters.
 * It is the default.
 */
song::song() {
    //default
}

/**
 * @brief Constructs a new Song object.
 * 
 * This constructor creates a new Song object with the given song name, song URI, and song artist.
 * 
 * @param songName Name of the song.
 * @param songURI Identifier for the song.
 * @param songArtist Song's artist.
 */
song::song(QString songName, QString songURI, QString songArtist) {
    this->songName = songName;
    this->songURI = songURI;
    this->songArtist = songArtist;
}

/**
 * @brief Destructs a Song object.
 */
song::~song() {
    //
}

/**
 * @brief Gets a song name.
 * 
 * @return A song name.
 */
QString song::getSongName() {
    return songName;
}

/**
 * @brief Gets a song identifier.
 *
 * @return The song identifier.
 */
QString song::getSongURI() {
    return songURI;
}

/**
 * @brief Gets a song artist.
 * 
 * @return The song artist.
 */
QString song::getSongArtist() {
    return songArtist;
}

/**
 * @brief Sets a song name.
 * 
 * @param newName The new song name.
 */
void song::setSongName(QString newName) {
    songName = newName;
}

/**
 * @brief Sets a song identifier.
 * 
 * @param songURI The new song identifier.
 */
void song::setSongURI(QString songURI) {
    this->songURI = songURI;
}

/**
 * @brief Sets a song artist.
 * 
 * @param songArtist The new song artist.
 */
void song::setSongArtist(QString songArtist) {
    this->songArtist = songArtist;
}
