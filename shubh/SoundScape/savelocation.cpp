#include "savelocation.h"
#include "QtQuick/qquickitem.h"
#include "ui_savelocation.h"
#include "Location.h"
#include <QMessageBox>

location::Location newLocation;

saveLocation::saveLocation(QWidget *parent) : QDialog(parent)
    , ui(new Ui::saveLocation)
{
    ui->setupUi(this);

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


void saveLocation::on_pushButton_saveNewLocation_clicked()
{

    QString name = ui->lineEdit_locationName->text();
    //PlaylistMap::PlaylistMap playlistMap();
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

    //push to nam's code to save location

}

