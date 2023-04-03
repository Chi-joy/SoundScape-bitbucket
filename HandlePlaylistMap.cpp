#include <iostream>
#include <chrono>
#include <ctime>
#include "PlaylistMap.cpp"
#include "GoogleAPI.cpp"


//handles the user commands that affect the playlistMap distribution
class HandlePlaylistMap{
public:

    //helper method to check if placing a new zone will overlap with the others
    bool checkOverlap(Location targetLocation ){

        //iterate through every existing zone and check for overlaps within the circumference
        for ( std::set<PlaylistMap>::iterator it = PlaylistMap::PlaylistMaps.begin(); it != PlaylistMap::PlaylistMaps.end(); i++ ){
            Location playlistLocation = it->getLocation();

            if ( distanceCheck(targetLocation, playlistLocation) <= 6800){
                //if an overlap exists return false to indicate failure
                return false;
            }
        }
        //if you don't find an overlap, return true
        return true;
    }


    //add in a playlist zone from the user at a target location, check for overlaps in location
    void addPlaylistMap(Playlist playlist, Location targetLocation){
        if(checkOverlap(targetLocation)){ 
            PlaylistMap insertMap = PlaylistMap(targetLocation,playlist);
            PlaylistMap::PlaylistMaps.insert(insertMap);
        } else{
            cout << "Invalid zone, overlap exists" << endl;
        }
    }

    //remove a playlist from the set
    void removePlaylistMap(PlaylistMap map){
        PlaylistMap::PlaylistMaps.erase(map);
    }
    
    //assign a playlist to a zone
    void setPlaylist(PlaylistMap map, Playlist playlist){
        auto it = PlaylistMap::PlaylistMaps.find(map);

        if(it != PlaylistMap::PlaylistMaps.end()){
            map.updatePlaylist(playlist);         
        } else{
            cout << "PlaylistMap invalid" << endl;
        }
    }
};