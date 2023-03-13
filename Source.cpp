/*
* Namashivayan Sivaram
* an app for printing all game results of 2022-2023 NHL regular season games
* 2022-02-06
*/
#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#define OS_WIN
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "json.hpp"
#include <string>
#include <cstring>
#include "GoogleAPI.h"
#include <vector>
#include "Location.h";
#ifdef OS_WIN
#include <Windows.h>
#define SLEEP_TIME Sleep(10000)
#else
#include <unistd.h>
#define SLEEP_TIME sleep(10)
#endif

using json = nlohmann::json;
using namespace std;
int main() {


    string url = "https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyAuBwWaguCyTIdFl5bW7gSlNgdjKhe4yhA";
    GoogleAPI Loc = GoogleAPI(url);
    //Loc.getLocation();
    std::cout << "Starting program... \n";
    Location myLoc = Location(0, 0);
    while (true) {
        Loc.getLocation();
        myLoc.setLat(Loc.getLocationLat());
        myLoc.setLng(Loc.getLocationLng());
        //checkMapChange(location);

        //TO NAMASHI: PARSE THE LOCATION OBJECT INTO LANG/LONG AND PRINT IT HERE        
        //location = location.parse(); //< PARSE THIS LOCATION OBJECT INTO LANG/LONG STRING AND PRINT HERE
        std::cout << "Current location: " << myLoc.getLat()<< " : "<<myLoc.getLng() << std::endl;


        SLEEP_TIME; // sleep for 10 seconds
    }


    return 0;
	

	
}