/*
* Namashivayan Sivaram
* an app for printing all game results of 2022-2023 NHL regular season games
* 2022-02-06
*/
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
//#include <unistd.h> //LINUX ONLY IF YOU ARE ON WINDOWS USE <windows.h> and change sleep to 10000
#include <Windows.h>
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


        Sleep(10000); // sleep for 10 seconds
    }


    return 0;
	

	
}