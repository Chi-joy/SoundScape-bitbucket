#include "savelocation.h"
#include "ui_savelocation.h"
#include "PlaylistMap.h"

location::Location newLocation;

saveLocation::saveLocation(QWidget *parent) : QDialog(parent)
    , ui(new Ui::saveLocation)
{
    ui->setupUi(this);

    ui->quickWidget_map_saveLocation->setSource(QUrl(QStringLiteral("qrc:/newLoc.qml")));


    //catch the signal from newLoc.qml file, update instance variables of latitude and longitude

//    QQuickItem * idfk = ui->quickWidget_map_saveLocation->rootObject();

//    QObject::connect(&idfk, &MapItemView::markerPositionChanged, [](const QtPositioning::QGeoCoordinate& position){
//            qDebug() << "Marker position changed:" << position.latitude() << position.longitude();
//        });




}

void saveLocation::setCoordinates(double latitude, double longitude) {

    newLocation.setLat(latitude);
    newLocation.setLng(longitude);

    //write new location to file

}

saveLocation::~saveLocation()
{
    delete ui;
}

void saveLocation::on_buttonBox_accepted()
{
    //PlaylistMap::PlaylistMap playlistMap();
    ui->quickWidget_map_saveLocation->rootObject();



}


