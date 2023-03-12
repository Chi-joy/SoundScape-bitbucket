#include <iostream>
#include <chrono>
#include <ctime>
#include "PlaylistMap.cpp"

class HandlePlaylistMap{
public:

    PlaylistMap currentMap;

    Location pingLocation(){
        while(true){
            //get current location

            //std::this_thread::sleep_for(std::chrono::seconds(10));  
            
        }
    }

    //check if a specific playlistMap is inside the set
    bool checkInMap(PlaylistMap playlist){
        return PlaylistMap::PlaylistMaps.find(playlist) != PlaylistMap::PlaylistMaps.end();
    }

    void addPlaylistMap(PlaylistMap map){
        PlaylistMap::PlaylistMaps.insert(map);
    }

    void removePlaylistMap(PlaylistMap map){
        PlaylistMap::PlaylistMaps.erase(map);
    }


    //call this from your main alongside pingLocation
    // i.e main: while true sleep 10 checkMapChange(pingLocation) + print(pingLocation)
    void checkMapChange(Location currentLocation){
        
    }
    


};