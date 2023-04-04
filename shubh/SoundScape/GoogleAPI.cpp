/**
 * @file GoogleAPI.h
 * @brief Header file for the GoogleAPI class.
 * 
 * This file contains the declaration of the GoogleAPI class, which
 * is a class that handles cURL requests to fetch data from a specified URL.
 * 
 * The GoogleAPI class is defined in this header file, and it includes a constructor and two methods to execute the cURL request and get the location data from the response.
 * 
 * @author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano 
 * @date 2022-02-06
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
/**
     * @brief Constructs a new GoogleAPI object.
     * 
     * This constructor creates a new GoogleAPI object with the given URL to perform
     * cURL requests.
     * 
     * @param URL The URL to fetch data from using cURL requests.
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

    /**
     * @brief Returns the latitude obtained from the cURL request.
     * 
     * This method returns the latitude obtained from the cURL request.
     * 
     * @returns The latitude obtained from the cURL request.
     */

double GoogleAPI::getLocationLat() {
    return lat;
}

/**
     * @brief Returns the longitude obtained from the cURL request.
     * 
     * This method returns the longitude obtained from the cURL request.
     * 
     * @returns The longitude obtained from the cURL request.
     */

double GoogleAPI::getLocationLng() {
    return lng;
}
