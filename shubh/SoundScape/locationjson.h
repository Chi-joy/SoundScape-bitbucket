#ifndef LOCATIONJSON_H
#define LOCATIONJSON_H
#include "Location.h"
#include "QtCore/qstring.h"
#include <vector>


class locationJson
{
public:
    locationJson();
    std::vector<location::Location>getLocations();
    void addLocation(location::Location location);
    void deleteLocation(location::Location location);
    void getLocation(QString name);
};

#endif // LOCATIONJSON_H
