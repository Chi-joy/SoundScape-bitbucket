/*
* Namashivayan Sivaram
* Class for handling cURL requests, getting data
* 2022-02-06
*/
#include "GoogleAPI.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;
/*
* GoogleAPI()
* constructor for request
* URL is a url for curl
*/
GoogleAPI::GoogleAPI(string URL) {
    url = URL;
}
/*
* execute()
* fetches data using curl reqeust from given URL
* returns true if request is success, otherwise false
*/
bool GoogleAPI::getLocation() {
    bool worked = true;
    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        locationItems.clear();
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &locationItems);
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        // Set the request body
        std::string request_body = R"({"considerIp": "true"})";
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request_body.c_str());

        // Set the content type header
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (CURLE_OK != res) {
            worked = false; //return false on Fail
            //cerr << "CURL error: " << res << endl;
        }
        else {

        }
    }
    curl_global_cleanup();
    if (worked) {
        //cout << locationItems << endl;
        json data = json::parse(locationItems);
        lat = data["location"]["lat"];
        lng = data["location"]["lng"];
        //yourLocation = new Location(lat,lng);

        ;
    }
    return(worked);


}
//get result of request
double GoogleAPI::getLocationLat() {
    return lat;
    //FOR CHI ********************* you want to change this to return yourLocation object i assume so youll have to change the 
    //method instance in the header file too
}
double GoogleAPI::getLocationLng() {
    return lng;
    //FOR CHI ********************* you want to change this to return yourLocation object i assume so youll have to change the 
    //method instance in the header file too
}
