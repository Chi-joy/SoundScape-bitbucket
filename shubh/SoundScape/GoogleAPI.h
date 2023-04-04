/**

@file GoogleAPI.h
@brief Header file for GoogleAPI class which handles cURL requests and fetches data.
@author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
@date 2022-02-06
*/

#pragma once
#ifndef REQ
#define REQ
#include <curl/curl.h>
#include <QString>

class GoogleAPI
{
private:
    std::string url;
    std::string locationItems;
    double lat;
    double lng;
	
    /**
     * @brief Helper function to write data received from cURL request
     * @param buffer Buffer to hold the data received from cURL request
     * @param size Size of the buffer
     * @param nmemb Number of members
     * @param param Parameter passed to cURL easy option
     * @return Total size of the buffer
    */
    static size_t my_write(void* buffer, size_t size, size_t nmemb, void* param)
    {
        std::string& text = *static_cast<std::string*>(param);
        size_t totalsize = size * nmemb;
        text.append(static_cast<char*>(buffer), totalsize);
        return totalsize;
    }
public:
    /**
    * @brief Constructor for GoogleAPI class
    * @param URL The url for the cURL request
    */
    GoogleAPI(std::string URL);
    /**
     * @brief Function to execute the cURL request and fetch the data
     * @return True if the request is successful, otherwise false
     */
    bool getLocation();
    /**
     * @brief Function to get the longitude of the location
     * @return The longitude of the location
     */
    double getLocationLng();
    /**
     * @brief Function to get the latitude of the location
     * @return The latitude of the location
     */
    double getLocationLat();
    /**
     * @brief Destructor for GoogleAPI class
     */
    ~GoogleAPI() {

    }
};
#endif
