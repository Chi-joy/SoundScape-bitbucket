
#include "QtCore/qstring.h"
#include "playlist.h"
#include "json.hpp"


#ifndef REQUEST_H   // To make sure you don't declare the function more than once by including the header multiple times.
#define REQUEST_H

void initRequest(QString authCode);
//std::vector<Playlist::playlist> createVector(nlohmann::json & myjson);
//std::vector<Game> createVector(nlohmann::json & myjson);
//void createVector(nlohmann::json myjson);



#endif
