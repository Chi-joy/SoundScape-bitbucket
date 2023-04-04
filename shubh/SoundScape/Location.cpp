/**

@file Location.cpp
@brief This file contains the definition of the Location class.
The Location class is used to store the latitude, longitude and name of a location.
The class also provides methods to get and set the values of the instance variables.
@author Your Name
@date 2023-04-03
*/

#include "Location.h"
#include <cmath>

using namespace location;

/**
 * @brief Default constructor for the Location class.
 * 
 * This constructor creates a Location object with default values for latitude and longitude (both 0.0).
 */
Location::Location() {
    //default
}

/**
 * @brief Constructor for the Location class.
 * 
 * This constructor creates a Location object with the given values for latitude and longitude.
 * 
 * @param lt The latitude of the location
 * @param ln The longitude of the location
 */
Location::Location(double lt, double ln) {

    this->latitude = lt;
    this->longitude = ln;
}

/**
 * @brief Constructor for the Location class.
 * 
 * This constructor creates a Location object with the given values for name, latitude and longitude.
 * 
 * @param name The name of the location
 * @param lt The latitude of the location
 * @param ln The longitude of the location
 */
Location::Location(QString name, double lt, double ln) {
    this->name = name;
    this->latitude = lt;
    this->longitude = ln;
}

/**
 * @brief Getter method for the latitude of the location.
 * 
 * @return The latitude of the location.
 */
double Location::getLat() {
    return latitude;
}

/**
 * @brief Getter method for the longitude of the location.
 * 
 * @return The longitude of the location.
 */
double Location::getLng() {
    return longitude;
}

/**
 * @brief Setter method for the latitude of the location.
 * 
 * @param lt The new latitude of the location.
 */
void Location::setLat(double lt) {
    latitude = lt;
}

/**
 * @brief Setter method for the longitude of the location.
 * 
 * @param lg The new longitude of the location.
 */
void Location::setLng(double lg) {
    longitude = lg;
}

/**
 * @brief Getter method for the name of the location.
 * 
 * @return The name of the location.
 */
QString Location::getName() {
    return name;
}

