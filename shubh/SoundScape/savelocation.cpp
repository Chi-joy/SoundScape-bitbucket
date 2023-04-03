#include "savelocation.h"
#include "QtQuick/qquickitem.h"
#include "ui_savelocation.h"
#include "Location.h"
#include "MetaData.h"
#include <QMessageBox>

location::Location newLocation;
QWidget * parentWindow;

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


    //catch the signal from newLoc.qml file, update instance variables of latitude and longitude

//    QQuickItem * idfk = ui->quickWidget_map_saveLocation->rootObject();

//    QObject::connect(&idfk, &MapItemView::markerPositionChanged, [](const QtPositioning::QGeoCoordinate& position){
//            qDebug() << "Marker position changed:" << position.latitude() << position.longitude();
//        });

}

//void saveLocation::setCoordinates(double latitude, double longitude) {

//    newLocation.setLat(latitude);
//    newLocation.setLng(longitude);

//    //write new location to file

//}


//helper method to check if placing a new zone will overlap with the others
bool checkOverlap(location::Location targetLocation ){

    Metadata m = Metadata();
    std::vector<location::Location> pV = m.buildDataLocation("locations.csv");
    int size = pV.size();

    //iterate through every existing zone and check for overlaps within the circumference
    for (int i = 0; i < size; i++){
        location::Location playlistLoc = pV.at(i);

        double latDiffSquared = (playlistLoc.getLat() - targetLocation.getLat()) * (playlistLoc.getLat() - targetLocation.getLat());
        double lngDiffSquared = (playlistLoc.getLng() - targetLocation.getLng()) * (playlistLoc.getLng() - targetLocation.getLng());

        if ( sqrt(latDiffSquared + lngDiffSquared) <= 3400){
            //if an overlap exists return true
            return true;
        }
    }
    //if you don't find an overlap return false
    return false;
}

void saveLocation::handleMySignal(double number1, double number2)
{
    qDebug() << "Received signal with values: " << number1 << ", " << number2;
    this->markerlatitude = number1;
    this->markerlongitude = number2;
    // Do something with the values here
}



saveLocation::~saveLocation()
{
    delete ui;
}

void saveLocation::on_pushButton_cancel_clicked()
{
    reject();
}


//called when they hit 'save' to make their new location
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

