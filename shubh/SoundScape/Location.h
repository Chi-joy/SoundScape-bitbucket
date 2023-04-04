/**

@brief The location namespace.
This namespace includes the Location class that represents a geographical location.
The class includes methods to set and get the name, latitude and longitude of the location.

*/

#ifndef LOCATION_H
#define LOCATION_H

#include "QtCore/qstring.h"
namespace location {

	/**
     * @brief A class to represent a geographical location.
     * 
     * This class includes methods to set and get the name, latitude and longitude of the location.
     * 
     */
    class Location {
        private:
            double latitude;
            double longitude;
            QString name;
    public:
      /**
       * @brief Default constructor for the Location class.
       */
        Location();
      
      /**
         * @brief Constructor for the Location class that sets the name, latitude and longitude.
         * 
         * @param name The name of the location.
         * @param lt The latitude of the location.
         * @param ln The longitude of the location.
         */
        Location(QString name, double lt, double ln);
      /**
         * @brief Constructor for the Location class that sets the latitude and longitude.
         * 
         * @param lt The latitude of the location.
         * @param ln The longitude of the location.
         */
        Location(double lt, double ln);
      /**
       * @brief Get the latitude of the location.
       * 
       * @return The latitude of the location.
       */
        double getLat();
        double getLng();
        QString getName();
        void setName(QString);
        void setLat(double);
        void setLng(double);
    };
}

#endif
