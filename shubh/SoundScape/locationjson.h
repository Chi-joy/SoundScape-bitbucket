/**

@brief The locationJson class provides functions to handle location data in JSON format.
It allows to retrieve, add and delete locations from a JSON file.
@author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
@date april 3 2022
*/

#ifndef LOCATIONJSON_H
#define LOCATIONJSON_H
#include "Location.h"
#include <QString>
#include <vector>


class locationJson
{
public:
/**
* @brief Constructs a new locationJson object.
*
*/
    locationJson();
    /**
     * @brief Returns all the locations stored in the JSON file.
     * 
     * @return std::vector<location::Location> A vector containing all the locations in the JSON file.
     */
    std::vector<location::Location>getLocations();
    /**
     * @brief Adds a location to the JSON file.
     * 
     * @param location The location to be added.
     */
    void addLocation(location::Location location);
    /**
     * @brief Deletes a location from the JSON file.
     * 
     * @param location The location to be deleted.
     */
    void deleteLocation(location::Location location);
    /**
     * @brief Retrieves a location from the JSON file given its name.
     * 
     * @param name The name of the location to retrieve.
     */
    void getLocation(QString name);
};

#endif // LOCATIONJSON_H
