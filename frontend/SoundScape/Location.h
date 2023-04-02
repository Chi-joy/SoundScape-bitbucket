#ifndef LOCATION_H
#define LOCATION_H
#include <QString>
namespace location {


    class Location {
        private:
            double latitude;
            double longitude;
            QString name;
    public:
        Location();
        Location(QString name, double lt, double ln);
        Location(double lt, double ln);
        double getLat();
        double getLng();
        double getName();
        void setName(QString);
        void setLat(double);
        void setLng(double);
        ~Location() {

        }
    };
}

#endif
