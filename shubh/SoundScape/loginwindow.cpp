#include "loginwindow.h"
#include "MetaData.h"

#include "spotifyapi.h"
#include "ui_loginwindow.h"
#include "GoogleAPI.h"
#include "savelocation.h"
#include "selectplaylistwidget.h"
#include "ui_selectplaylistwidget.h"

#include <QDesktopServices>
#include <QMessageBox>
#include <QStringListModel>
#include <QQuickItem>
#include <QGeoCoordinate>
#include <QThread>

//actually the main window

saveLocation * saveLocationN;
selectPlaylistWidget * playlistMapWindow;
SpotifyAPI * spotifyAPI;

//dummy playlist for when nothing is playing
Playlist::playlist dummy("dummy", "dummy", "dummy", false);

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{

    //thread for pinging in the background
    QThread* workerThread = new QThread();
    MyWorker *worker = new MyWorker();

    worker->moveToThread(workerThread);
    //signals connecting thread and loginWindow
    connect(workerThread, &QThread::started, worker, &MyWorker::doWork);
//    QObject::connect(worker,SIGNAL(messageRecieved(Playlist::playlist &p)),this,SLOT(handleWorkerMessage(Playlist::playlist &p)));
    connect(worker, &MyWorker::messageReceived, this, &LoginWindow::handleWorkerMessage, Qt::QueuedConnection);


    ui->setupUi(this);

    //sets location and playlistmap lists
    setLists();

    this->isLoggedIn = false;

   // ui->groupBox_login->hide();

    //hide non login related things
    connect(ui->pushButton_spotify, &QPushButton::released, this, &LoginWindow::createSpotifyObject);
    ui->groupBox_pushButtons->hide();
    ui->groupBox_playlists->hide();

    ui->quickWidget_map->hide();
    ui->groupBox_playlistMaps->hide();
    ui->quickWidget_map->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    ui->groupBox_locations->hide();

    //save new location window connected to push button
    saveLocationN = new saveLocation(this);
    connect(ui->pushButton_createLocation, &QPushButton::clicked, saveLocationN, &saveLocation::exec);

    this->playlistPlaying = dummy;

}

void LoginWindow::handleWorkerMessage(Playlist::playlist p)
{
    // check if playlist is playlist playing
    //play playlist
    qDebug() << "Message received in LoginWindow: " << p.getPlaylistName();

    //mutex.lock();
    if (p.getPlaylistName() != this->playlistPlaying.getPlaylistName()) {
        this->playlistPlaying = p;
        spotifyAPI->playSong(&p);
    }
    //mutex.unlock();

}


void LoginWindow::setLists() {

    //set locations in listbox
    Metadata m = Metadata();
    QStringListModel *locationModel = new QStringListModel(this);

    std::vector<location::Location> locationVector = m.buildDataLocation("locations.csv");

    int size = locationVector.size();
    QStringList locationNames;

    for (int i = 0; i < size; i++) {
        location::Location tempLocation = locationVector[i];
        locationNames.append(tempLocation.getName());
    }

    locationModel->setStringList(locationNames);
    ui->listView_locations->setModel(locationModel);

    //set playlistmaps list in listbox
    QStringListModel *playlistMapsModel = new QStringListModel(this);

    std::vector<PlaylistMap> playlistMapVector = m.buildData("mdata.csv");

    size = playlistMapVector.size();
    QStringList playlistMapNames;

    for (int i = 0; i < size; i++) {
        PlaylistMap tempMap = playlistMapVector[i];

        //its returning url for name and playlistname for location name
        QString q = tempMap.getPlaylist().getPlaylistName() + " X " + tempMap.getLocation().getName();
        playlistMapNames.append(q);
    }

    playlistMapsModel->setStringList(playlistMapNames);
    ui->listView_playlistMaps->setModel(playlistMapsModel);




}


void LoginWindow::getLocations() {



}

//called when 'connect to spotify' is pressed
void LoginWindow::createSpotifyObject() {



    //authenticate user
    spotifyAPI = new SpotifyAPI();
    spotifyAPI->authenticate();

    QMessageBox::information(this, "Connecting to Spotify", "Connecting to Spotify......Please wait for your browser to redirect.");

    //hide/show some features
    ui->pushButton_spotify->hide();
    ui->pushButton_playlists->show();
    ui->pushButton_createLocation->show();
    ui->quickWidget_map->show();
    ui->listView_playlists->show();

    // connect(worker, &MyWorker::messageReceived, this, &LoginWindow::handleWorkerMessage);




    this->isLoggedIn = true;

    //**********starting the thread below

    //workerThread->start();






}

LoginWindow::~LoginWindow()
{
   // delete this->spotifyAuth;
    emit stopWorkerThread();
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
        ui->groupBox_locations->show();


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

            Metadata m = Metadata();
            std::vector<location::Location> locationVector = m.buildDataLocation("locations.csv");
            QModelIndex index = ui->listView_locations->currentIndex();
            QString selectedText = index.data(Qt::DisplayRole).toString();

            int size = locationVector.size();

            for (int i = 0; i < size; i++) {
                if (locationVector.at(i).getName() == selectedText) {
                    locationVector.erase(locationVector.begin() + i);
                    m.writeDataLocation(locationVector, "locations.csv");
                }
            }

        } else {

        }

        setLists();

    }
}


void LoginWindow::on_pushButton_createPMap_clicked()
{
    playlistMapWindow = new selectPlaylistWidget(this);


    QStringListModel *model = new QStringListModel(this);
    ui->groupBox_playlists->show();
    std::vector<Playlist::playlist> playlistVector = spotifyAPI->getVector();
    Playlist::playlist p = playlistVector.at(1);
    spotifyAPI->playSong(&p);
    playlistMapWindow->setPlaylistVector(playlistVector);
    int size = playlistVector.size();
    QStringList playlistNames;

    for (int i = 0; i < size; i++) {
        Playlist::playlist tempPlaylist = playlistVector[i];
        playlistNames.append(tempPlaylist.getPlaylistName());
    }

    model->setStringList(playlistNames);

    playlistMapWindow->ui->listView_playlists->setModel(model);
    playlistMapWindow->show();
}


void LoginWindow::on_pushButton_refreshLists_clicked()
{
    setLists();
}


void LoginWindow::on_pushButton_editPMaps_clicked()
{

    QItemSelectionModel *selectionModel = ui->listView_playlistMaps->selectionModel();
    location::Location dummyLoc("dummy", 0, 0);
    PlaylistMap * map = new PlaylistMap(dummyLoc, dummy);


    //dies if no locations
    if (!selectionModel->hasSelection()) {
        QMessageBox::information(this, "Error!", "Please select a playlist map from list");

    } else {
        Metadata m = Metadata();
        std::vector<PlaylistMap> playlistMapVector = m.buildData("mdata.csv");
        QModelIndex index = ui->listView_playlistMaps->currentIndex();
        QString selectedText = index.data(Qt::DisplayRole).toString();
        QStringList list = selectedText.split(" X ");
        QString playlistName = list[0];
        QString locationName = list[1];
        int size = playlistMapVector.size();

        for (int i = 0; i < size; i++) {

            bool locationMatch = playlistMapVector.at(i).getLocation().getName() == locationName;
            bool playlistMatch = playlistMapVector.at(i).getPlaylist().getPlaylistName() == playlistName;
            if (locationMatch && playlistMatch) {
                map = &playlistMapVector.at(i);
                break;
            }
        }


    playlistMapWindow = new selectPlaylistWidget(this);


    QStringListModel *model = new QStringListModel(this);
    ui->groupBox_playlists->show();
    std::vector<Playlist::playlist> playlistVector = spotifyAPI->getVector();
   // Playlist::playlist p = playlistVector.at(1);
    //spotifyAPI->playSong(&p);
    playlistMapWindow->setPlaylistVector(playlistVector);
    PlaylistMap pM = *map;
    playlistMapWindow->setFields(pM);
    size = playlistVector.size();
    QStringList playlistNames;

    for (int i = 0; i < size; i++) {
        Playlist::playlist tempPlaylist = playlistVector[i];
        playlistNames.append(tempPlaylist.getPlaylistName());
    }

    model->setStringList(playlistNames);

    playlistMapWindow->ui->listView_playlists->setModel(model);
    playlistMapWindow->show();
    }

}

