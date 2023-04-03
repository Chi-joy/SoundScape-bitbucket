#include <iostream>
#include <map>
#include <set>

class Location {
  private:
    double latitude;
    double longitude;

  public:
    Location(double lat, double lng) : latitude(lat), longitude(lng) {}
    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }
};

class Playlist {
  // playlist class definition
};

class PlaylistMap{
    public:
        static std::set<PlaylistMap> PlaylistMaps;

        PlaylistMap(Location location, Playlist playlist) {

            this->location = location;
            this->playlist = playlist;
        }

        void PlaylistMap::updatePlaylist(Playlist updatedPlaylist){
          this->playlist = updatedPlaylist;
        }
        
        void PlaylistMap::updateLocation(Location updatedLocation){
          this-> location = updatedLocation;
        }

        Playlist PlaylistMap::getPlaylist(){
          return this->playlist;
        }
        
        Location PlaylistMap::getLocation(){
          return this->location;
        }


    //converts degrees to radians
    double toRadians(double degrees) {
        return degrees * M_PI / 180.0;
    }

    //returns distance in km
    double distanceCheck(Location currentLocation, Location playlistLocation){
        double distLat = toRadians(playlistLocation.latitude - currentLocation.latitude);
        double distLong = toRadians(playlistLocation.longitude - currentLocation.longitude);

        double a = pow(sin(distLat / 2), 2) + cos(toRadians(currentLocation.latitude)) * cos(toRadians(playlistLocation.latitude)) * pow(sin(distLong / 2), 2);
        double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    }
    private:
        Location location;
        Playlist playlist;

};