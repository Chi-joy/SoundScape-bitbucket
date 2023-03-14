# CMakeList.txt : CMake project for SoundScape8.0, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SoundScape8.0")

# Add source to this project's executable.
add_executable (SoundScape8.0 "SoundScape8.0.cpp" "SoundScape8.0.h" "GoogleAPI.h" "GoogleAPI.cpp" "json.hpp" "BackgroundController.cpp" "PlaylistMap.h" "PlaylistMap.cpp" "Playlist.h" "Location.h" "Location.cpp" "HandlePlaylistMap.cpp")
find_package(CURL REQUIRED)
target_include_directories(SoundScape8.0 PRIVATE ${CURL_INCLUDE_DIR})
target_link_libraries(SoundScape8.0 PRIVATE CURL::libcurl)
# TODO: Add tests and install targets if needed.
