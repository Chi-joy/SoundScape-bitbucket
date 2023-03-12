#pragma once
#include "Location.h"
#include <map>
#include <set>
#include "Playlist.h"
class PlaylistMap {
private:
    Location location;
    Playlist playlist;
public:
    //static std::set<PlaylistMap> PlaylistMaps;

    PlaylistMap(Location loc, Playlist pl) :location(loc), playlist(pl) {

        location = loc;
        playlist = pl;
    }

    void updatePlaylist(Playlist updatedPlaylist);

    void updateLocation(Location updatedLocation);

    Playlist getPlaylist();

    Location getLocation();




};