#include "Location.h"

location::Location(double lt, double ln):latitude(lt),longitude(ln) {
	latitude = lt;
	longitude = ln;
}
double location::getLat() {
	return latitude;
}
double location::getLng() {
	return longitude;
}
void location::setLat(double lt) {
	latitude = lt;
}
void location::setLng(double lg) {
	longitude = lg;
}
