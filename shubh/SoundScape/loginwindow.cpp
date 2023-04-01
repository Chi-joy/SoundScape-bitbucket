#include "loginwindow.h"
#include "spotifyapi.h"
#include "ui_loginwindow.h"
#include "GoogleAPI.h"
#include "savelocation.h"
#include "selectplaylistwidget.h"

#include <QDesktopServices>
#include <QMessageBox>
#include <QStringListModel>
#include <QQuickItem>
#include <QGeoCoordinate>

    SpotifyAPI * spotifyAPI;
    saveLocation * saveLocationN;
    selectPlaylistWidget * playlistMap;

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    getLocations();

   // ui->groupBox_login->hide();
    connect(ui->pushButton_spotify, &QPushButton::released, this, &LoginWindow::createSpotifyObject);
    ui->groupBox_pushButtons->hide();
    ui->groupBox_playlists->hide();

    ui->quickWidget_map->hide();
    ui->groupBox_playlistMaps->hide();
    ui->quickWidget_map->setSource(QUrl(QStringLiteral("qrc:/main.qml")));

    saveLocationN = new saveLocation(this);

    connect(ui->pushButton_createLocation, &QPushButton::clicked, saveLocationN, &saveLocation::exec);
    //connect(ui->pushButton_createPMap, &QPushButton::clicked, playlistMap, &selectPlaylistWidget::exec);

    //ui->quickWidget_map->rootObject()->setProperty("centerCoordinate", QVariant::fromValue(QGeoCoordinate(43.009953,-81.273613)));


    //connect(this, &LoginWindow::saveLocationClicked, ui->qmlWidget, &QQuickWidget::requestUpdate);
    //import playlist playlistmap.cpp, then store the coordinates in a Location object
//    ///*
//    auto obj = ui->quickWidget_map->rootObject();*/
   // connect(this, SIGNAL(setCenter(double,double)), obj, SLOT(setCenter(double,double)));




}

void LoginWindow::getLocations() {

}

void LoginWindow::createSpotifyObject() {



    spotifyAPI = new SpotifyAPI();
    spotifyAPI->authenticate();

    QMessageBox::information(this, "Connecting to Spotify", "Connecting to Spotify......Please wait for your browser redirect.");
    ui->pushButton_spotify->hide();
    ui->pushButton_playlists->show();
    ui->pushButton_createLocation->show();
    ui->quickWidget_map->show();
    ui->listView_playlists->show();

}

LoginWindow::~LoginWindow()
{
   // delete this->spotifyAuth;
    delete ui;
}


void LoginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username != "test" || password != "test") {
        QMessageBox::information(this, "error", "wrong username or pass");
    } else {
        //QMessageBox::information(this, "success", "nice");
        ui->groupBox_login->hide();
        ui->pushButton_playlists->hide();
        ui->pushButton_spotify->show();
        ui->groupBox_pushButtons->show();
        ui->quickWidget_map->show();
        ui->groupBox_playlistMaps->show();
        ui->groupBox_playlists->show();


    }
}


void LoginWindow::on_pushButton_playlists_clicked()
{


    QStringListModel *model = new QStringListModel(this);
    ui->groupBox_playlists->show();
    std::vector<Playlist::playlist> playlistVector = spotifyAPI->getVector();
    int size = playlistVector.size();
    QStringList playlistNames;

    for (int i = 0; i < size; i++) {
        Playlist::playlist tempPlaylist = playlistVector[i];
        playlistNames.append(tempPlaylist.getPlaylistName());
    }

    model->setStringList(playlistNames);
    ui->listView_playlists->setModel(model);

}


void LoginWindow::on_pushButton_coor_clicked()
{
    std::string url = "https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyAuBwWaguCyTIdFl5bW7gSlNgdjKhe4yhA";
    GoogleAPI googleAPI(url);
    bool worked = googleAPI.getLocation();
    if (worked) {
        QString lat = QString::number( googleAPI.getLocationLat());
        QString lng = QString::number(googleAPI.getLocationLng());
        QString message = "Latitude: " + lat + " Longitude: " + lng;
        QMessageBox::information(this, "your location is....", message);

        double latidudeD = googleAPI.getLocationLat();
        double longitudeD = googleAPI.getLocationLng();
        //emit setCenter(googleAPI.getLocationLat(), googleAPI.getLocationLng());
        //ui->quickWidget_map->rootObject()->setProperty("centerCoordinate", QVariant::fromValue(QGeoCoordinate(latidudeD, longitudeD)));

//        // Get the 'map' QML item from the QQuickWidget
//        QQuickItem *map = ui->quickWidget_map->rootObject()->findChild<QQuickItem*>("map");

//        // Create a new camera object with the desired location and zoom level
//        QGeoCoordinate newCenterCoordinate(latidudeD, longitudeD);
//        QGeoViewCamera newCamera(newCenterCoordinate, 12);

//        // Animate the map to the new camera position and zoom level
//        QVariant animation = map->property("activeMapItem").value<QObject*>()->createAnimation(newCamera);
//        animation.value<QAbstractAnimation*>()->start();

    }



}


void LoginWindow::on_pushButton_createLocation_clicked()
{
    //dies if the methods not here idk why
    //leave empty

}


void LoginWindow::on_pushButton_editLocation_clicked()
{
    QItemSelectionModel *selectionModel = ui->listView_locations->selectionModel();

    //dies if no locations
    if (!selectionModel->hasSelection()) {
        QMessageBox::information(this, "Error!", "Please select a location to delete from list");
    } else {
        int result = QMessageBox::question(this, "Confirmation", "Are you sure you wish to delete this location?");

        if (result) {
            //delete location method called from nams code

        }

        else {
            return;
        }
    }
}


void LoginWindow::on_pushButton_createPMap_clicked()
{
    playlistMap = new selectPlaylistWidget(this);

    playlistMap->show();
}

