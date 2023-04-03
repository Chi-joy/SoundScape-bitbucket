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

void LoginWindow::createSpotifyObject() {

    spotifyAPI = new SpotifyAPI();
    spotifyAPI->authenticate();
    ui->pushButton_spotify->hide();
    ui->pushButton_playlists->show();
    ui->pushButton_coor->show();


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
        QMessageBox::information(this, "success", "nice");
        ui->groupBox_login->hide();
        ui->pushButton_spotify->show();


    }
}


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

