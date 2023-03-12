
#include <vector>
#include "json.hpp"

#ifndef SPOTIFY_API   // To make sure you don't declare the function more than once by including the header multiple times.
#define SPOTIFY_API

void getPlaylists(std::string accessToken);
//std::vector<Game> createVector(nlohmann::json & myjson);
//void createVector(nlohmann::json myjson);



#endif
