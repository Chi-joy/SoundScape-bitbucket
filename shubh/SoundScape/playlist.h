/**
 * @file playlist.h
 * @brief Header file of the playlist class.
 * 
 * This file contains the declaration of the playlist class, which
 * holds a playlist.
 * 
 * @author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
 */

#include "Song.h"

#ifndef PLAYLIST_H   // To make sure you don't declare the function more than once by including the header multiple times.
#define PLAYLIST_H

namespace Playlist {
    
    class playlist {

    private:
        QString playlistName;
        QString playlistURI;
        QString playlistCoverURI;
        bool hasLocation;

    public:
      	/**
 		* @brief Constructs a new playlist object.
 		* 
 		* This constructor creates a new playlist object with no parameters.
 		* It is the default.
 		*/
        playlist();
      
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
        playlist(QString playlistName, QString playlistURL, QString playlistCoverURI, bool hasLocation);
      
      	/**
 		* @brief Gets a playlist name.
 		* 
 		* @return A playlist name
 		*/
        QString getPlaylistName();
      
      	/**
 		* @brief Gets a playlist identifier.
 		* 
 		* @return A playlist identifier.
 		*/
        QString getPlaylistURI();
      
      	/**
 		* @brief Gets a playlist cover identifier.
 		* 
 		* @return A playlist cover identifier.
 		*/
        QString getPlaylistCoverURI();

      	/**
 		* @brief Sets a playlist name.
 		* 
 		* @param newName The new playlist name.
 		*/
        void setPlaylistName(QString newName);
      
      	/**
 		* @brief Sets a playlist identifier.
 		* 
 		* @param newURI The new playlist identifier.
 		*/
        void setPlaylistURI(QString songURI);
      
      	/**
 		* @brief Sets a playlist cover identifier.
 		* 
 		* @param newCoverURI The new playlist cover identifier.
 		*/
        void setPlaylistCoverURI(QString songArtist);
    };

    
}

#endif
