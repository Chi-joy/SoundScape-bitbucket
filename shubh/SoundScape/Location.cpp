#include "Location.h"
#include <cmath>

/**

@brief The Location class represents a geographic location with latitude and longitude coordinates and a name.
The Location class can be used to store information about a geographic location, including its latitude and longitude coordinates and a name.
@author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
@date 2023-04-03
*/
using namespace location;

Location::Location() {
    //default
}

/**
* @brief Constructor for the Location class that takes in latitude and longitude coordinates.
* @param lt The latitude of the location.
* @param ln The longitude of the location.
*/

Location::Location(double lt, double ln) {

    this->latitude = lt;
    this->longitude = ln;
}

/**
* @brief Constructor for the Location class that takes in a name, latitude, and longitude coordinates.
* @param name The name of the location.
* @param lt The latitude of the location.
* @param ln The longitude of the location.
*/
Location::Location(QString name, double lt, double ln) {
    this->name = name;
    this->latitude = lt;
    this->longitude = ln;
}

/**
* @brief Returns the latitude of the location.
* @return The latitude of the location.
*/
double Location::getLat() {
    return latitude;
}

/**
* @brief Returns the longitude of the location.
* @return The longitude of the location.
*/
double Location::getLng() {
    return longitude;
}

/**
* @brief Sets the latitude of the location.
* @param lt The new latitude of the location.
*/
void Location::setLat(double lt) {
    latitude = lt;
}

/**
* @brief Sets the longitude of the location.
* @param lt The new longitude of the location.
*/
void Location::setLng(double lg) {
    longitude = lg;
}

/**
* @brief Returns the name of the location.
* @return The name of the location.
*/
QString Location::getName() {
    return name;
}

