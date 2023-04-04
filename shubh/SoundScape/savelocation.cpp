/**
 * @file savelocation.cpp
 * @brief Implementation of the savelocation class.
 * 
 * This file contains the implementation of the savelocation class, which
 * is used to save a location for a user.
 * 
 * @author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
 */

#include "savelocation.h"
#include "QtQuick/qquickitem.h"
#include "ui_savelocation.h"
#include <QMessageBox>

location::Location newLocation;
QWidget * parentWindow;

/**
 * @brief Constructs a new saveLocation dialog.
 *
 * @param parent The parent widget of the dialog.
 */
saveLocation::saveLocation(QWidget *parent) : QDialog(parent)
    , ui(new Ui::saveLocation)
{

    ui->setupUi(this);

    parentWindow = parent;

    ui->quickWidget_map_saveLocation->setSource(QUrl(QStringLiteral("qrc:/newLoc.qml")));

    QQuickItem::connect(ui->quickWidget_map_saveLocation->rootObject(), SIGNAL(markerPositionChanged(double,double)),
                     this, SLOT(handleMySignal(double,double)));

    this->markerlatitude = 0;
    this->markerlongitude = 0;
}

/**
 * @brief Converts degrees to radians.
 *
 * @param degrees The degrees to be converted to radians.
 */
double saveLocation::toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

/**
 * @brief Calculates the distance between two locations.
 *
 * @param currentLocation The current location.
 * @param playlistLocation The location of a playlist item.
 * @return The distance between the two locations in kilometers.
 */
double saveLocation::distanceCheck(location::Location currentLocation, location::Location playlistLocation){
    double distLat = toRadians(playlistLocation.getLat() - currentLocation.getLat());
    double distLong = toRadians(playlistLocation.getLng() - currentLocation.getLng());

    double a = pow(sin(distLat / 2), 2) + cos(toRadians(currentLocation.getLat())) * cos(toRadians(playlistLocation.getLat())) * pow(sin(distLong / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance =  6371 * c;

    return distance;
}


/**
 * @brief Checks if placing a new zone will overlap with existing zones.
 * This is a helper method.
 *
 * @param targetLocation The location of the new zone.
 * @return true if the new zone will overlap with existing zones, false otherwise.
 */
bool saveLocation::checkOverlap(location::Location targetLocation ){

    Metadata m = Metadata();
    std::vector<location::Location> pV = m.buildDataLocation("locations.csv");
    int size = pV.size();

    //iterate through every existing zone and check for overlaps within the circumference
    for (int i = 0; i < size; i++){
        location::Location playlistLoc = pV.at(i);

        if ( distanceCheck(targetLocation, playlistLoc) <= 3.4){
            //if an overlap exists return true
            return true;
        }
    }
    //if you don't find an overlap return false
    return false;
}

/**
 * @brief Slot function that sets the member variables markerlatitude and markerlongitude to the
 * values of the signal, which represent the latitude and longitude of a marker on a map.
 * The function can be used to update the position of a marker on a map based on the
 * values of the signal.
 *
 * @param number1 The latitude of the marker.
 * @param number2 The longitude of the marker.
 */
void saveLocation::handleMySignal(double number1, double number2)
{
    qDebug() << "Received signal with values: " << number1 << ", " << number2;
    this->markerlatitude = number1;
    this->markerlongitude = number2;
}

/**
 * @brief The destructor of the saveLocation class.
 *
 * This destructor deletes the user interface object of the saveLocation class.
 * It is called when an instance of the class is destroyed, and it ensures that
 * any memory allocated by the user interface object is properly freed.
 */
saveLocation::~saveLocation()
{
    delete ui;
}

/**
 * @brief Function that is called when the "Cancel" button is clicked 
 * in the user interface of the saveLocation class. The function rejects the
 * dialog, which closes the dialog without saving any changes. This function
 * can be used to cancel any pending changes to the dialog and close it.
 */
void saveLocation::on_pushButton_cancel_clicked()
{
    reject();
}


/**
 * @brief Slot function that is called when the "Save" button is clicked in the
 * user interface of the saveLocation class to create a new location.
 *
 * The function reads the name of the new location from a text input field, and checks if a valid location has
 * been selected on the map. If the inputs are valid and the new location does not overlap
 * with any existing locations, it is added to a CSV file containing all the saved locations,
 * and the dialog is closed. If the new location overlaps with an existing location, an error
 * message is displayed and the location is not saved.
 *
 */
void saveLocation::on_pushButton_saveNewLocation_clicked()
{

    QString name = ui->lineEdit_locationName->text();
    //PlaylistMap::PlaylistMap playlistMap();

    //validating inputs
    if (name.size() == 0) {
        QMessageBox::information(this,"Error!" , "Please enter a name for your location");
        return;
    }

    if (this->markerlatitude == 0 && this->markerlongitude == 0) {
        QMessageBox::information(this,"Error!" , "Select a location on the map");
        return;
    }

    ui->quickWidget_map_saveLocation->rootObject();
    location::Location newLoc(name, this->markerlatitude, this->markerlongitude);

    //check if newlocation overlaps with another
    if (!checkOverlap(newLoc)) {

        //if no, push to locations.csv
        Metadata m = Metadata();
        std::vector<location::Location> l = m.buildDataLocation("locations.csv");

        l.push_back(newLoc);
        m.writeDataLocation(l, "locations.csv");
        accept();
    } else {
        QMessageBox::information(this,"Error!" , "Your location overlaps with another! Please select another zone");
    }
}

