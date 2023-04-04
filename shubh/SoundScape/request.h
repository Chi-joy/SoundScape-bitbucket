/**
 * @file
 * @brief This file contains the implementation of a program that interacts with the Spotify Web API to retrieve playlists.
 */
#include "playlist.h"
#include "json.hpp"



#ifndef REQUEST_H   // To make sure you don't declare the function more than once by including the header multiple times.
#define REQUEST_H

/**
 * @brief A function used to send a request to the Spotify API and retrieve an access token.
 * 
 * @param authCode The authorization code used to request the access token.
 * @return A QString containing the access token.
 */
QString initRequest(std::string authCode);

/**
 * @brief A function used to set the access token retrieved from the Spotify API.
 * 
 * @param myjson A nlohmann::json object containing the access token data.
 */
void setToken(nlohmann::json & myjson);

/**
 * @brief A function used to send a request to the Spotify API and retrieve a user's playlists.
 * 
 * @param accessToken The access token used to authenticate the request.
 */
void getPlaylists(std::string accessToken);

/**
 * @brief A function used to extract the playlist data from a JSON object returned by the Spotify API.
 * 
 * @param myjson A reference to a nlohmann::json object containing the playlist data.
 * @return A vector containing Playlist objects, each representing a playlist.
 */
std::vector<Playlist::playlist> createVector(nlohmann::json & myjson);




#endif
