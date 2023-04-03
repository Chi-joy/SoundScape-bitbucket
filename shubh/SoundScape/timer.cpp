//#include "timer.h"
//#include "GoogleAPI.h"
//#include "MetaData.h"
//#include "QtCore/qtimer.h"
//#include <QCoreApplication>
//#include <QThread>


//PlaylistMap * currentMap;

//timer::timer(QObject *parent)
//    : QObject{parent}
//{

//    location::Location loc("dummy", 0, 0);
//    Playlist::playlist playlist("dummy", "dummy", "dummy", false);
//    currentMap = new PlaylistMap(loc, playlist);
//    runTimer();



//}

//void timer::runTimer() {
//    QTimer * timer = new QTimer(this);
//    QObject::connect(timer, &QTimer::timeout, this, &timer::pingLocation);
//    timer->start(1000);
//}



////timer::pingingBackground() {
////    location::Location loc("dummy", 0, 0);
////    Playlist::playlist playlist("dummy", "dummy", "dummy", false);
////    currentMap = new PlaylistMap(loc, playlist);
////    //default
////}
//location::Location timer::pingLocation(){


//    std::string url = "https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyAuBwWaguCyTIdFl5bW7gSlNgdjKhe4yhA";
//    //getting metadata
//    GoogleAPI Loc = GoogleAPI(url);
//    Loc.getLocation();

//    location::Location currentLocation;
//    currentLocation.setLat(Loc.getLocationLat());
//    currentLocation.setLng(Loc.getLocationLng());
//    checkMapChange(currentLocation);
//    return(currentLocation);

//}

////converts degrees to radians
//double toRadians(double degrees) {
//    return degrees * M_PI / 180.0;
//}

////returns distance in km
//double distanceCheck(location::Location currentLocation, location::Location playlistLocation){
//    double distLat = toRadians(playlistLocation.getLat() - currentLocation.getLat());
//    double distLong = toRadians(playlistLocation.getLng() - currentLocation.getLng());

//    double a = pow(sin(distLat / 2), 2) + cos(toRadians(currentLocation.getLat())) * cos(toRadians(playlistLocation.getLat())) * pow(sin(distLong / 2), 2);
//    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
//    double distance =  6371 * c;

//    return distance;
//}




////Method to detect a map change and return playlist accordingly
//Playlist::playlist timer::checkMapChange(location::Location currentLocation){

//        Metadata m = Metadata();
//        std::vector<PlaylistMap> pV = m.buildData("mdata.csv");
//        int size = pV.size();

//        for (int i = 0; i < size; i++){
//            PlaylistMap tempMap = pV.at(i);
//            location::Location playlistLoc = pV.at(i).getLocation();

//            double latDiffSquared = (playlistLoc.getLat() - currentLocation.getLat()) * (playlistLoc.getLat() - currentLocation.getLat());
//            double lngDiffSquared = (playlistLoc.getLng() - currentLocation.getLng()) * (playlistLoc.getLng() - currentLocation.getLng());

//            //if they're already in the map, dont send another copy of map
//            bool locationSame = tempMap.getLocation().getName() == currentMap->getLocation().getName();
//            bool playlistSame = tempMap.getPlaylist().getPlaylistName() == currentMap->getPlaylist().getPlaylistName();
//            if (locationSame && playlistSame ) {
//                continue;
//            }

//            //get distance between coordinates
//            if ( distanceCheck(currentLocation, playlistLoc) <= 3.4){

//                //if logged into spotify, play song
//                //if (this->isLoggedIn) {

//                    Playlist::playlist p = pV.at(i).getPlaylist();
//                    PlaylistMap * pM = &pV.at(i);
//                    currentMap = pM;
//                    return p;

//                    //spotifyAPI->playSong(&p);

//                //}

//            }
//        }

//        //dummy playlist to return if no match
//        Playlist::playlist dummy("dummy","dummy","dummy", false);
//        return dummy;
//        //if you don't find an overlap return false


//}
