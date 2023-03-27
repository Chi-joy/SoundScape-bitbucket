#pragma once
#include "Location.h"

#include "playlist.h"
class PlaylistMap {
private:
    Location location;
    Playlist::playlist playlist;
public:
    //static std::set<PlaylistMap> PlaylistMaps;

    PlaylistMap(Location loc, Playlist::playlist pl) :location(loc), playlist(pl) {

        location = loc;
        playlist = pl;
    }

    void updatePlaylist(Playlist::playlist updatedPlaylist);

    void updateLocation(Location updatedLocation);

    Playlist::playlist getPlaylist();

    Location getLocation();




};
