#include "GoogleAPI.h"
#include "Location.h"
#include "MetaData.h"
#include "pingingBackground.h"
#include <QCoreApplication>
#include <QThread>


pingingBackground::pingingBackground() {
    //default
}
location::Location pingingBackground::pingLocation(){


    std::string url = "https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyAuBwWaguCyTIdFl5bW7gSlNgdjKhe4yhA";
    //getting metadata
    GoogleAPI Loc = GoogleAPI(url);
    Loc.getLocation();

    location::Location currentLocation;
    currentLocation.setLat(Loc.getLocationLat());
    currentLocation.setLng(Loc.getLocationLng());
    return(currentLocation);

}




//Method to detect a map change and return playlist accordingly
Playlist::playlist pingingBackground::checkMapChange(location::Location currentLocation){

        Metadata m = Metadata();
        std::vector<PlaylistMap> pV = m.buildData("mdata.csv");
        int size = pV.size();

        for (int i = 0; i < size; i++){
            location::Location playlistLoc = pV.at(i).getLocation();

            double latDiffSquared = (playlistLoc.getLat() - currentLocation.getLat()) * (playlistLoc.getLat() - currentLocation.getLat());
            double lngDiffSquared = (playlistLoc.getLng() - currentLocation.getLng()) * (playlistLoc.getLng() - currentLocation.getLng());

            if ( sqrt(latDiffSquared + lngDiffSquared) <= 3400){

                //if logged into spotify, play song
                //if (this->isLoggedIn) {

                    Playlist::playlist p = pV.at(i).getPlaylist();
                    return p;

                    //spotifyAPI->playSong(&p);

                //}

            }
        }

        //dummy playlist to return if no match
        Playlist::playlist dummy("dummy","dummy","dummy", false);
        return dummy;
        //if you don't find an overlap return false


}
