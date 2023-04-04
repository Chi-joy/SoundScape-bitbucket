/**
 * @file Song.h
 * @brief Header file of the song class.
 * 
 * This file contains the declaration of the song class, which
 * holds a song.
 * 
 * @author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
 */

#include "QtCore/qstring.h"
#include <string>
#include <iostream>
#include <vector>

#ifndef SONG_H   // To make sure you don't declare the function more than once by including the header multiple times.
#define SONG_H

namespace Song {
    
    class song {

    private:
        QString songName;
        QString songURI;
        QString songArtist;

    public:
      	/**
 		* @brief Constructs a new Song object.
 		* 
 		* This constructor creates a new Song object with no parameters.
 		* It is the default.
 		*/
        song();
      
      	/**
 		* @brief Constructs a new Song object.
 		* 
 		* This constructor creates a new Song object with the given song name, song URI, and song artist.
 		* 
 		* @param songName name of the song
		* @param songURI identifier for the song
		* @param songArtist song's artist
		*/
        song(QString songName, QString songURI, QString songArtist);
        
      	/**
 		* @brief Destructs a Song object.
 		*/
      	~song();
      
      	/**
 		* @brief Gets a song name.
 		* 
 		* @return songName returns a song name
 		*/
        QString getSongName();
      
      	/**
 		* @brief Gets a song identifier.
 		*
 		* @return songURI returns the song identifier 
 		*/
        QString getSongURI();
      
      	/**
 		* @brief Gets a song artist.
 		* 
 		* @return songArtist returns the song artist
 		*/
        QString getSongArtist();

        /**
 		* @brief Sets a song name.
 		* 
		* @param newName the new song name
 		*/
      	void setSongName(QString newName);
      
      	/**
 		* @brief Sets a song identifier.
		* 
 		* @param songURI the new song identifier
 		*/
        void setSongURI(QString songURI);
      
      	/**
 		* @brief Sets a song artist.
 		* 
 		* @param songArtist the new song artist
 		*/
        void setSongArtist(QString songArtist);
    };
    
}

#endif
