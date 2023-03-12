#include <iostream>
#include <map>
#include <set>

class Location {
  private:
    double latitude;
    double longitude;
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

        bool PlaylistMap::checkOverlap(Location input){
          
          
          // if lang/long same? Check with google API for this
          return 0;
        } 
    private:
        Location location;
        Playlist playlist;

};

// std::set<PlaylistMap> PlaylistMap::PlaylistMaps;