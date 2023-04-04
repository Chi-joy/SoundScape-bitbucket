/**
 * @file spotifyapi.h
 * @brief Header file of the spotifyapi class.
 * 
 * This file contains the declaration of the spotiftyapi class, which
 * uses the Spotify API.
 * 
 * @author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
 */

#ifndef SPOTIFYAPI_H
#define SPOTIFYAPI_H

#include "QtNetworkAuth/qoauth2authorizationcodeflow.h"
#include <QObject>
#include "request.h"


class SpotifyAPI : public QObject
{
    Q_OBJECT
public:

	/**
	 * @brief Constructor for the SpotifyAPI class.
 	*
 	* This constructor creates a new instance of the SpotifyAPI class and initializes the
 	* QOAuth2AuthorizationCodeFlow object used for authentication.
 	*
 	* @param parent The parent object for the new instance.
 	*/
    explicit SpotifyAPI(QObject *parent = nullptr);
    
    /**
 	* @brief This function authenticates the user with the Spotify API.
 	*/
    void authenticate();
    
    /**
 	* @brief Sets up the authentication flow for the Spotify API.
 	*
 	* This function sets up the authentication flow for the Spotify API by configuring the
 	* QOAuth2AuthorizationCodeFlow object used for authentication, setting various URLs,
 	* and connecting signals and slots. It also sets up a QOAuthHttpServerReplyHandler to
 	* handle the OAuth2 callback URL.
 	*/
    void setUpAuth();
    
    /**
 	* @brief This function calls the Spotify API to get a list of playlists for the current user.
 	*/
    void callGetPlaylist();
    
    /**
 	* @brief Slot function that is called when a network reply has finished downloading data.
 	* 
 	* This function reads the data from the network reply and parses it into a nlohmann::json object.
 	* It then calls the createVector() function to convert the JSON object into a vector of Playlist objects,
 	* which is stored in the playlistVector member variable of the class.
 	* 
 	* @param reply A pointer to the QNetworkReply object that finished downloading data.
 	*/
    void downloadFinished(QNetworkReply * reply);
    
    /**
 	* @brief Plays a song from the given playlist on the user's Spotify account.
 	*
 	* @param p A pointer to a Playlist::playlist object containing the URI of the playlist to play.
 	*/
    void playSong(Playlist::playlist *);
    
    /**
 	* @brief This function returns a vector of Playlist objects.
 	*
 	* This function returns the private member variable playlistVector, which is a vector of Playlist
 	* objects. The Playlist class represents a Spotify playlist and contains information such as the playlist's
 	* name, owner, and track list.
 	*
 	* @return A vector of Playlist objects.
 	*/
    std::vector<Playlist::playlist> getVector();
    QString accessToken;

private:

    QOAuth2AuthorizationCodeFlow * spotifyAuth;
    
    /**
 	* @brief Sets the authorization code for the OAuth2 authentication flow and initiates the request to obtain an access token.
 	* 
 	* @param v The authorization code as a QString.
 	*/
    void setAuthCode(QString v);
    QString authCode;

    std::vector<Playlist::playlist> playlistVector;

signals:

};

#endif // SPOTIFYAPI_H
