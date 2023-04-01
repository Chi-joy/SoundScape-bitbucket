#include "Location.h"
#include <cmath>

using namespace location;

Location::Location() {
    //default
}

Location::Location(double lt, double ln) {
    latitude = lt;
    longitude = ln;
}
double Location::getLat() {
    return latitude;
}
double Location::getLng() {
    return longitude;
}
void Location::setLat(double lt) {
    latitude = lt;
}
void Location::setLng(double lg) {
    longitude = lg;
}
