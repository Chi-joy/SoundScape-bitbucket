#pragma once
#include "Location.h"
#include <QQmlEngine>

#include "playlist.h"

/**
 * @brief Represents a mapping between a location and a playlist.
 */
class PlaylistMap {
private:
    location::Location location; /**< The location associated with this PlaylistMap. */
    Playlist::playlist playlist; /**< The playlist associated with this PlaylistMap. */
public:
    //static std::set<PlaylistMap> PlaylistMaps;

    /**
     * @brief Constructs a new PlaylistMap object with the given location and playlist.
     *
     * @param loc The location to be associated with this PlaylistMap.
     * @param pl The playlist to be associated with this PlaylistMap.
     */
    PlaylistMap(location::Location loc, Playlist::playlist pl) :location(loc), playlist(pl) {

        location = loc;
        playlist = pl;
    }

    /**
     * @brief Updates the playlist for this PlaylistMap object.
     *
     * @param updatedPlaylist The updated playlist to be set for this PlaylistMap.
     */
    void updatePlaylist(Playlist::playlist updatedPlaylist);

    /**
     * @brief Updates the location for this PlaylistMap object.
     *
     * @param updatedLocation The updated location to be set for this PlaylistMap.
     */
    void updateLocation(location::Location updatedLocation);

    /**
     * @brief Returns the current playlist for this PlaylistMap object.
     *
     * @return The current playlist.
     */
    Playlist::playlist getPlaylist();

    /**
     * @brief Returns the current location for this PlaylistMap object.
     *
     * @return The current location.
     */
    location::Location getLocation();
};

