#include "PlaylistMap.h"

void PlaylistMap::updatePlaylist(Playlist::playlist updatedPlaylist){
    this->playlist = updatedPlaylist;
}
        
void PlaylistMap::updateLocation(location::Location updatedLocation){
    this-> location = updatedLocation;
}

Playlist::playlist PlaylistMap::getPlaylist(){
    return this->playlist;
}
        
location::Location PlaylistMap::getLocation(){
    return this->location;
}




    



// std::set<PlaylistMap> PlaylistMap::PlaylistMaps;
