//#include <iostream>
//#include <chrono>
//#include <ctime>
////#include <io.h>
//#include <QString>
//#include <unistd.h> //LINUX ONLY IF YOU ARE ON WINDOWS USE <windows.h> and change sleep to 10000
//#include "PlaylistMap.h"
//#include "GoogleAPI.h"

//class BackgroundController{
    
//    public:

//    //the current map the user is on
//    PlaylistMap currentMap;

//    location::Location pingLocation(){
        
//        QString url = "https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyAuBwWaguCyTIdFl5bW7gSlNgdjKhe4yhA";
//        //getting metadata
//        GoogleAPI Loc = GoogleAPI(url.toStdString());
//        bool worked = Loc.getLocation();
//        location::Location currentLocation(0,0);
//        if (worked) {
//            currentLocation.setLat(Loc.getLocationLat());
//            currentLocation.setLng(Loc.getLocationLng());
//        }

//        //string GEOLOC = Loc.locationResult();

//        //TO NAMASHI: make a location object with GEOLOC or have the google API return, then return it here
//        //location::Location currentLocation;
//        //currentLocation.latitude = GEOLOG.latitude;

//        return(currentLocation);
        
//    }

//    //Method to detect a map change and swap the current PlaylistMap
//    void checkMapChange(location::Location currentLocation){
        
//       //for every map in PlaylistMaps static object, check location of current from pingLocation against them
//        //if match, then update currentMap to the one that it matches/
//        // work on in phase 2
        
//    }

//};

////run this
//int main() {

//    std::cout << "Starting program... \n";
//    BackgroundController * b;

//    while (true) {

//        location::Location location = b->pingLocation();

//        //checkMapChange(location);

//        //TO NAMASHI: PARSE THE LOCATION OBJECT INTO LANG/LONG AND PRINT IT HERE
//        //location = location.parse(); //< PARSE THIS LOCATION OBJECT INTO LANG/LONG STRING AND PRINT HERE
//        QString lat = QString::number(location.getLat());
//        QString lng = QString::number(location.getLng());
//        QString currentLocation = "Current location: " + lat + " , " + lng + "\n";
//        std::cout << currentLocation.toStdString() << std::endl;

        
//        sleep(10); // sleep for 10 seconds
//    }

    
//    return 0;
//}
