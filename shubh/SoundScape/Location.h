#ifndef LOCATION_H
#define LOCATION_H
namespace location {


    class Location {
        private:
            double latitude;
            double longitude;
    public:
        Location();
        Location(double lt, double ln);
        double getLat();
        double getLng();
        void setLat(double);
        void setLng(double);
        ~Location() {

        }
    };
}

#endif
