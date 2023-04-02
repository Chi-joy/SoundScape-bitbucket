#include <iostream>
#include <chrono>
#include <ctime>
#include "HandlePlaylistMap.cpp"
#include "GoogleAPI.cpp"
#include<io.h>
#include <unistd.h> //LINUX ONLY IF YOU ARE ON WINDOWS USE <windows.h> and change sleep to 10000
#include "PlaylistMap.cpp"


//class that handles the background effects of playlist map, such as passive location updates and area changes
class BackgroundController{
    
    public:

    //the current map the user is on
    PlaylistMap currentMap;

    Location pingLocation(){
        
        string url = "https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyAuBwWaguCyTIdFl5bW7gSlNgdjKhe4yhA";
        //getting metadata
        GoogleAPI Loc = GoogleAPI(url);
        Loc.getLocation();
        string GEOLOC = Loc.locationResult();

        Location currentLocation;
        currentLocation.latitude = GEOLOG.latitude;
        currentLocation.longitude = GEOLOG.longitude;
        return(currentLocation);
        
    }

    //Method to detect a map change and swap the current PlaylistMap
    //if it detects a map change it updates, if current user is within none of them then exit
    void checkMapChange(Location currentLocation){
        
        for ( std::set<PlaylistMap>::iterator it = PlaylistMap::PlaylistMaps.begin(); it != PlaylistMap::PlaylistMaps.end(); i++ ){   
            Location playlistLoc = it->getLocation();
            if ( sqrt((playlistLoc.latitude - currentLocation.latitude)^2 + (playlistLoc.longitude - currentLocation.longitude)^2) <= 3400){
                currentMap = *it;
                break;
            }
        }
        currentMap = NULL;
        
    }

};

//run this
int main() {

    std::cout << "Starting program... \n"

    while (true) {
        
        checkMapChange(pingLocation());

        sleep(10); // sleep for 10 seconds
    }

    
    return 0;
}