#include "loginwindow.h"
#include "spotifyapi.h"
#include "ui_loginwindow.h"
#include "GoogleAPI.h"

#include <QDesktopServices>
#include <QMessageBox>
#include <QStringListModel>
#include <QQuickItem>

    SpotifyAPI * spotifyAPI;
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

   // ui->groupBox_login->hide();
    connect(ui->pushButton_spotify, &QPushButton::released, this, &LoginWindow::createSpotifyObject);
    ui->groupBox_pushButtons->hide();
    ui->groupBox_playlists->hide();

    ui->quickWidget_map->hide();
    ui->quickWidget_map->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    auto obj = ui->quickWidget_map->rootObject();
   // connect(this, SIGNAL(setCenter(double,double)), obj, SLOT(setCenter(double,double)));
    connect(ui->playlistPair, SIGNAL(clicked()), this, SIGNAL(playlistPair_clicked()));




}

void LoginWindow::createSpotifyObject() {



    spotifyAPI = new SpotifyAPI();
    spotifyAPI->authenticate();

    QMessageBox::information(this, "Connecting to Spotify", "Connecting to Spotify......Please wait for your browser redirect.");
    ui->pushButton_spotify->hide();
    ui->pushButton_playlists->show();
    ui->pushButton_coor->show();
    ui->quickWidget_map->show();
    ui->listView_playlists->show();
    ui->pushButton_playlistPair->show();

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
        emit setCenter(googleAPI.getLocationLat(), googleAPI.getLocationLng());

    }

}

