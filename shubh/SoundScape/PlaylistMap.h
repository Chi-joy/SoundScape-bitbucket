#pragma once
#include "Location.h"
#include <QQmlEngine>

#include "playlist.h"
class PlaylistMap {
private:
    location::Location location;
    Playlist::playlist playlist;
public:
    //static std::set<PlaylistMap> PlaylistMaps;

    PlaylistMap(location::Location loc, Playlist::playlist pl) :location(loc), playlist(pl) {

        location = loc;
        playlist = pl;
    }

    void updatePlaylist(Playlist::playlist updatedPlaylist);

    void updateLocation(location::Location updatedLocation);

    Playlist::playlist getPlaylist();

    location::Location getLocation();



};
