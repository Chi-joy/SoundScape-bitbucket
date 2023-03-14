#pragma once
class Location {
    private:
        double latitude;
        double longitude;
public:
    Location(double lt, double ln);
    double getLat();
    double getLng();
    void setLat(double);
    void setLng(double);
    ~Location() {

    }
};
