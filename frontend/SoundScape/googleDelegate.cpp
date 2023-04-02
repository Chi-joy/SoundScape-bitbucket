#include "GoogleAPI.h"

class googleDelete{
public:
    QString getLocationMessage();
};

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
