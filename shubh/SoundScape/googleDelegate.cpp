/**

@file googleDelegate.cpp
@brief Defines googleDelete class and getLocationMessage() function
@author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
@date 2022-02-06
*/
#include "GoogleAPI.h"

/**
@class googleDelete
@brief This class provides functionality to delete Google data
*/
class googleDelete{
public:
  /*
  @brief Returns the location message
  @return The location message in a QString format
  */
    QString getLocationMessage();
};

/**

@brief Fetches location data using GoogleAPI object and returns location message in QString format
@return Location message in QString format if request was successful, otherwise "fail"
@note This function uses GoogleAPI object to fetch location data
*/
QString getLocationMessage() {
        std::string url = "https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyAuBwWaguCyTIdFl5bW7gSlNgdjKhe4yhA";
        GoogleAPI googleAPI(url);
        bool worked = googleAPI.getLocation();
        if (worked) {
            QString lat = QString::number( googleAPI.getLocationLat());
            QString lng = QString::number(googleAPI.getLocationLng());
            QString message = "Latitude: " + lat + " Longitude: " + lng;
            return message;

        }
        return "fail";
}
