/*
* Namashivayan Sivaram
* Header for Request object file
* 2022-02-06
*/
#ifndef REQ
#define REQ
#include <string>
#include <cstring>
#include <iostream>
#include <curl/curl.h>
#include "json.hpp"

class GoogleAPI
{
private:
	std::string url;
    std::string locationItems;
    double lat;
    double lng;
    
    //Location yourLocation;
    static size_t my_write(void* buffer, size_t size, size_t nmemb, void* param)
    {
        std::string& text = *static_cast<std::string*>(param);
        size_t totalsize = size * nmemb;
        text.append(static_cast<char*>(buffer), totalsize);
        return totalsize;
    }
public:
    GoogleAPI(std::string URL);
    bool getLocation();
    double getLocationLng();
    double getLocationLat();
    ~GoogleAPI() {

    }
};
#endif
