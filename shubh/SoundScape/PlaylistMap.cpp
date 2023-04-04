#include "PlaylistMap.h"

/**
 * @brief Updates the playlist for this PlaylistMap object.
 *
 * @param updatedPlaylist The updated playlist to be set for this PlaylistMap.
 */
void PlaylistMap::updatePlaylist(Playlist::playlist updatedPlaylist){
    this->playlist = updatedPlaylist;
}
        
/**
 * @brief Updates the location for this PlaylistMap object.
 *
 * @param updatedLocation The updated location to be set for this PlaylistMap.
 */
void PlaylistMap::updateLocation(location::Location updatedLocation){
    this-> location = updatedLocation;
}

/**
 * @brief Returns the current playlist for this PlaylistMap object.
 *
 * @return The current playlist.
 */
Playlist::playlist PlaylistMap::getPlaylist(){
    return this->playlist;
}
        
/**
 * @brief Returns the current location for this PlaylistMap object.
 *
 * @return The current location.
 */
location::Location PlaylistMap::getLocation(){
    return this->location;
}




    



