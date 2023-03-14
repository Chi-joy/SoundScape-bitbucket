
#include "QtCore/qstring.h"
#include "playlist.h"
#include "json.hpp"


#ifndef REQUEST_H   // To make sure you don't declare the function more than once by including the header multiple times.
#define REQUEST_H


QString initRequest(std::string authCode);
void setToken(nlohmann::json & myjson);
void getPlaylists(std::string accessToken);
std::vector<Playlist::playlist> createVector(nlohmann::json & myjson);
//std::vector<Playlist::playlist> createVector(nlohmann::json & myjson);
//std::vector<Game> createVector(nlohmann::json & myjson);
//void createVector(nlohmann::json myjson);



#endif
