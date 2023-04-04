/**

@file loginwindow.cpp
@brief Implementation of LoginWindow class, which represents the main window of the application.
It provides a user interface for logging in, accessing Spotify API, and displaying user's playlists.
@author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
@date 2023-04-03
*/

#include "loginwindow.h"
#include "Location.h"
#include "spotifyapi.h"
#include "GoogleAPI.h"

#include "ui_loginwindow.h"
#include <QDesktopServices>
#include <QMessageBox>
#include <QStringListModel>
#include <QQuickView>

    SpotifyAPI * spotifyAPI;
/**

@brief Constructs a LoginWindow object.

@param parent Pointer to the parent widget.
*/
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);


   // ui->groupBox_login->hide();
    connect(ui->pushButton_spotify, &QPushButton::released, this, &LoginWindow::createSpotifyObject);
    ui->pushButton_spotify->hide();
    ui->pushButton_playlists->hide();
    ui->groupBox_playlists->hide();
    ui->pushButton_coor->hide();



}

/**
@brief Creates an instance of SpotifyAPI and authenticates the user.
*/
void LoginWindow::createSpotifyObject() {

    spotifyAPI = new SpotifyAPI();
    spotifyAPI->authenticate();
    ui->pushButton_spotify->hide();
    ui->pushButton_playlists->show();
    ui->pushButton_coor->show();


}

/**
@brief Destroys the LoginWindow object.
*/

LoginWindow::~LoginWindow()
{
   // delete this->spotifyAuth;
    delete ui;
}

/**

@brief Handles the login button click event.

If the user enters incorrect login credentials, an error message is displayed.

Otherwise, the Spotify button is displayed.
*/
void LoginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username != "test" || password != "test") {
        QMessageBox::information(this, "error", "wrong username or pass");
    } else {
        QMessageBox::information(this, "success", "nice");
        ui->groupBox_login->hide();
        ui->pushButton_spotify->show();


    }
}

/**

@brief Handles the playlists button click event.

Retrieves the user's playlists from SpotifyAPI and displays them in a list view.
*/
void LoginWindow::on_pushButton_playlists_clicked()
{


    QStringListModel *model = new QStringListModel(this);
    ui->pushButton_playlists->hide();
    std::vector<Playlist::playlist> playlistVector = spotifyAPI->getVector();
    int size = playlistVector.size();
    QStringList playlistNames;

    for (int i = 0; i < size; i++) {
        Playlist::playlist tempPlaylist = playlistVector[i];
        playlistNames.append(tempPlaylist.getPlaylistName());
    }

    model->setStringList(playlistNames);
    ui->groupBox_playlists->show();
    ui->listView_playlists->setModel(model);

}

/**

@brief Handles the coordinate button click event.
Retrieves the user's location using GoogleAPI and displays the latitude and longitude in a message box.
*/
void LoginWindow::on_pushButton_coor_clicked()
{
    QQuickView view;
    view.setSource(QUrl::fromLocalFile("main.qml"));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.resize(1024, 768);
    view.show();
    double lat;
    double lng;
    std::string url = "https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyAuBwWaguCyTIdFl5bW7gSlNgdjKhe4yhA";
    GoogleAPI googleApi(url);
    bool worked = googleApi.getLocation();
    if (worked) {

        lat = googleApi.getLocationLat();
        lng = googleApi.getLocationLng();
        QString locationLat = "Latitude: " + QString::number(lat);
        QString locationLng = "Longitude: " + QString::number(lng);
        QString message = locationLat + " and " + locationLng;
        QMessageBox::information(this, "Your coordinates are", message);
    }

}

