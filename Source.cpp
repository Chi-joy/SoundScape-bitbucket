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
using json = nlohmann::json;
using namespace std;
int main() {
	string url = "https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyAuBwWaguCyTIdFl5bW7gSlNgdjKhe4yhA";
	//getting metadata
	GoogleAPI Loc = GoogleAPI(url);
	Loc.getLocation();
	string GEOLOC = Loc.locationResult();
	cout << GEOLOC << endl;
	

	
}