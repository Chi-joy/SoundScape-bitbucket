#include "Location.h"
#include <cmath>

using namespace location;

Location::Location() {
    //default
}

Location::Location(double lt, double ln) {

    this->latitude = lt;
    this->longitude = ln;
}

Location::Location(QString name, double lt, double ln) {
    this->name = name;
    this->latitude = lt;
    this->longitude = ln;
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
QString Location::getName() {
    return name;
}
