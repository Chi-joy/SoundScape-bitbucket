/**

@brief The loginWindow class is responsible for handling user authentication through Spotify and Google APIs.
This class is the initial window the user is presented with, and is responsible for handling user authentication
through both Spotify and Google APIs. Upon successful authentication, the user will be directed to the playlist selection
screen (selectPlaylistWidget).
@author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
*/

#include "loginwindow.h"
#include "MetaData.h"

#include "QtCore/qjsondocument.h"
#include "QtCore/qjsonobject.h"
#include "QtNetwork/qnetworkaccessmanager.h"
#include "pingingBackground.h"
#include "spotifyapi.h"
#include "ui_loginwindow.h"
#include "GoogleAPI.h"
#include "savelocation.h"
#include "selectplaylistwidget.h"
#include "ui_selectplaylistwidget.h"
#include "timer.h"

#include <QDesktopServices>
#include <QMessageBox>
#include <QStringListModel>
#include <QQuickItem>
#include <QGeoCoordinate>
#include <QThread>
#include <QWaitCondition>
#include <thread>
#include <QNetworkReply>
#include <QInputDialog>

//actually the main window

saveLocation * saveLocationN;
selectPlaylistWidget * playlistMapWindow;
SpotifyAPI * spotifyAPI;
QString accessToken;

GoogleAPI *gAPI = new GoogleAPI("https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyAuBwWaguCyTIdFl5bW7gSlNgdjKhe4yhA");

location::Location loc("dummy", 0, 0);
Playlist::playlist playlist("dummy", "dummy", "dummy", false);
PlaylistMap * currentMapp = new PlaylistMap(loc, playlist);
bool isPlaying = false;
QMutex mtx;
QWaitCondition cv;
int count = 0;
bool updated = false;

//dummy playlist for when nothing is playing
Playlist::playlist dummy("dummy", "dummy", "dummy", false);

//class WorkerThread : public QThread {
//public:
//    WorkerThread(QLabel* label) : m_label(label) {}

//    void stop() {
//        m_stop = true;
//    }

//protected:
//    void run() override {
//        while (!m_stop) {
//            mtx.lock();
//            cv.wait(&mtx);
//            QString text = QString("Count: %1").arg(::count);
//            m_label->setText(text);
//            updated = false;
//            mtx.unlock();
//        }
//    }

//private:
//    QLabel* m_label;
//    bool m_stop = false;

//};

/**

@brief Converts degrees to radians.
@param degrees The angle in degrees to be converted.
@return The equivalent angle in radians.
*/
//converts degrees to radians
double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

/**

@brief Calculates the distance in kilometers between two locations.

Uses the Haversine formula to calculate the distance between two locations on the Earth's surface.

@param currentLocation The current location.

@param playlistLocation The location of the playlist.

@return The distance in kilometers between the two locations.
*/
//returns distance in km
double distanceCheck(location::Location currentLocation, location::Location playlistLocation){
    double distLat = toRadians(playlistLocation.getLat() - currentLocation.getLat());
    double distLong = toRadians(playlistLocation.getLng() - currentLocation.getLng());

    double a = pow(sin(distLat / 2), 2) + cos(toRadians(currentLocation.getLat())) * cos(toRadians(playlistLocation.getLat())) * pow(sin(distLong / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance =  6371 * c;

    return distance;
}



//void random_number_generator(WorkerThread* workerThread) {
//    //std::string url = "https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyAuBwWaguCyTIdFl5bW7gSlNgdjKhe4yhA";
//    //getting metadata
//    //GoogleAPI Loc = GoogleAPI(url);
//    while (true) {


//        gAPI->getLocation();

//        location::Location currentLocation;
//        currentLocation.setLat(gAPI->getLocationLat());
//        currentLocation.setLng(gAPI->getLocationLng());
//        Playlist::playlist p = checkMapChange(currentLocation);

////        std::this_thread::sleep_for(std::chrono::seconds(5));
////        int random_number = rand() % 10 + 1;
////        std::cout << "Random number generated: " << random_number << std::endl;

//        if (p.getPlaylistName() != "dummy") {

//            QNetworkAccessManager *mgr = new QNetworkAccessManager();
//            const QUrl url(QStringLiteral("https://api.spotify.com/v1/me/player/play"));
//            QNetworkRequest request(url);
//            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
//            std::string authBearder = "Bearer " + accessToken.toStdString();
//            request.setRawHeader("Authorization", authBearder.c_str());
//            QJsonObject obj;
//            obj["context_uri"] = p.getPlaylistURI();
//            obj["position_ms"] = "0";
//            QJsonDocument doc(obj);
//            QByteArray data = doc.toJson();

//            QByteArray requestData = data; // the request body data
//            QString requestUrl = url.toString(); // the request URL
//            QStringList requestHeaders;
//            foreach(QByteArray header, request.rawHeaderList()){
//                requestHeaders.append(header + ": " + request.rawHeader(header));
//            }
//            qDebug() << "Request URL: " << requestUrl;
//            qDebug() << "Request Headers: " << requestHeaders.join("\n");
//            qDebug() << "Request Data: " << QString(requestData);

//            // or
//            //QNetworkReply *reply = mgr->post(request, data);
//            QNetworkReply *reply = mgr->put(request, data);

//            QObject::connect(reply, &QNetworkReply::finished, [=](){
//                if(reply->error() == QNetworkReply::NoError){
//                    QString contents = QString::fromUtf8(reply->readAll());
//                    qDebug() << contents;
//                }
//                else{
//                    QString err = reply->errorString();
//                    qDebug() << err;
//                }
//            });

//            int i = 0;
//            //QMetaObject::invokeMethod(workerThread->parent(), "callPlaySong");
//            //workerThread->metaObject()->invokeMethod(workerThread->parent(), "callPlaySong", Qt::QueuedConnection);
//            //spotifyAPI->playSong(&p);
//        }

////        if (random_number == 5) {
////            std::unique_lock<QMutex> lock(mtx);

////            ::count++;
////            updated = true;
////            lock.unlock();
////            cv.notify_one();
////            std::cout << "Count updated to: " << ::count << std::endl;
////        }

////        if (workerThread->isInterruptionRequested()) {
////            return;
////        }
//    }
//}
//WorkerThread *workerThread;

/**

@brief Constructor for LoginWindow class
@param parent Parent widget (default is nullptr)
*/
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{



    //thread for pinging in the background
//    QThread* workerThread = new QThread();
//    MyWorker *worker = new MyWorker(this);
//    location::Location loc("dummy", 0, 0);
//    Playlist::playlist playlist("dummy", "dummy", "dummy", false);
//    currentMapp = new PlaylistMap(loc, playlist);

//    worker->moveToThread(workerThread);
//    //signals connecting thread and loginWindow
//    connect(workerThread, &QThread::started, worker, &MyWorker::doWork);
////    QObject::connect(worker,SIGNAL(messageRecieved(Playlist::playlist &p)),this,SLOT(handleWorkerMessage(Playlist::playlist &p)));
//    connect(worker, &MyWorker::messageReceived, this, &LoginWindow::handleWorkerMessage, Qt::QueuedConnection);


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

    //setWindowTitle("Qt Random Number Generator");



}

/**

@brief Calls the playSong function of SpotifyAPI object with the current playlist.
Gets the current playlist of the currentMapp object and calls the playSong function of the
SpotifyAPI object with the current playlist.
*/
void LoginWindow::callPlaySong() {
    Playlist::playlist p = currentMapp->getPlaylist();
    spotifyAPI->playSong(&p);
}

////converts degrees to radians
//double toRadians(double degrees) {
//    return degrees * M_PI / 180.0;
//}

////returns distance in km
//double distanceCheck(location::Location currentLocation, location::Location playlistLocation){
//    double distLat = toRadians(playlistLocation.getLat() - currentLocation.getLat());
//    double distLong = toRadians(playlistLocation.getLng() - currentLocation.getLng());

//    double a = pow(sin(distLat / 2), 2) + cos(toRadians(currentLocation.getLat())) * cos(toRadians(playlistLocation.getLat())) * pow(sin(distLong / 2), 2);
//    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
//    double distance =  6371 * c;

//    return distance;
//}

/**

@brief Checks if there is a change in the location on the map and returns the corresponding playlist

@param currentLocation The current location of the user

@return The playlist corresponding to the new location or a dummy playlist if there is no match
*/
Playlist::playlist checkMapChange(location::Location currentLocation){

        Metadata m = Metadata();
        std::vector<PlaylistMap> pV = m.buildData("mdata.csv");
        int size = pV.size();

        for (int i = 0; i < size; i++){
            PlaylistMap tempMap = pV.at(i);
            location::Location playlistLoc = pV.at(i).getLocation();

            double latDiffSquared = (playlistLoc.getLat() - currentLocation.getLat()) * (playlistLoc.getLat() - currentLocation.getLat());
            double lngDiffSquared = (playlistLoc.getLng() - currentLocation.getLng()) * (playlistLoc.getLng() - currentLocation.getLng());

            //if they're already in the map, dont send another copy of map
//            bool locationSame = tempMap.getLocation().getName() == currentMapp->getLocation().getName();
//            bool playlistSame = tempMap.getPlaylist().getPlaylistName() == currentMapp->getPlaylist().getPlaylistName();
//            if (locationSame && playlistSame ) {
//                continue;
//            }

            //get distance between coordinates
            if ( distanceCheck(currentLocation, playlistLoc) <= 3.4){

                //if logged into spotify, play song
                //if (this->isLoggedIn) {

                    Playlist::playlist p = pV.at(i).getPlaylist();
                    PlaylistMap * pM = &pV.at(i);
                    currentMapp= pM;
                    return p;

                    //spotifyAPI->playSong(&p);

                //}

            }
        }

        //dummy playlist to return if no match
        Playlist::playlist dummy("dummy","dummy","dummy", false);
        return dummy;
        //if you don't find an overlap return false


}

//void whileLoop() {
//    QEventLoop * eventLoop = new QEventLoop();
//    pingingBackground * ping = new pingingBackground();
//    while (true) {
//        // Do some work in the background
//        //mutex.lock();
//        eventLoop->processEvents();

//        location::Location curLoc = ping->pingLocation();
//        //Playlist::playlist p = ping->checkMapChange(curLoc);
//        QString latnlng = QString::number(curLoc.getLat()) + "," + QString::number(curLoc.getLng());

//        //if (p.getPlaylistName() != "dummy") {
//           // emit messageReceived(latnlng);
//            //qDebug() << "Message sent from MyWorker";
//        //}

//        //mutex.unlock();
//        QThread::msleep(10*1000); // Sleep for 10 seconds (in milliseconds)
//    }
//}

/**

@brief Handles the message received from the worker thread.

This function takes a QString argument 'coor' which contains the latitude and longitude

values separated by a comma. The function parses these values, creates a new location::Location

object with these values, and calls the checkMapChange() function to check for any changes

in the user's location.

If there is a change in the location and the playlist being played is not the same as the

new playlist, this function sets the new playlist as the currently playing playlist and

plays it using the spotifyAPI object.

@param coor A QString containing the latitude and longitude values separated by a comma.
**/
void LoginWindow::handleWorkerMessage(QString coor)
{
    // check if playlist is playlist playing
    //play playlist
    QStringList list = coor.split(",");
    double lat = list[0].toDouble();
    double lng = list[1].toDouble();

    qDebug() << "Message received in LoginWindow: " << coor;

    //mutex.lock();
//    if (p.getPlaylistName() != this->playlistPlaying.getPlaylistName()) {
//        this->playlistPlaying = p;
//        spotifyAPI->playSong(&p);
//    }
    location::Location currentLocation("currentLocation", lat, lng);
    //checkMapChange(currentLocation);
    //mutex.unlock();

}

/**
 * Pulls metadata and intializes saved locations and 
 * saved playlist maps
 */
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

/**
 * called when connet to spotify is pressed, opens new windows and
 * authenticates user for spotify usage
 */
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
    accessToken = spotifyAPI->accessToken;



    this->isLoggedIn = true;

    QLabel *label = new QLabel(this);

}

/**
 * Destrutor for login window, destroys the UI
 */
LoginWindow::~LoginWindow()
{
   // delete this->spotifyAuth;

/*    workerThread->stop();  // stop the worker thread
    workerThread->wait();  // wait for the worker thread to finish
    delete workerThread; */  // delete the worker thread object
    delete ui;
}


/**
 * Handles the event when the 'Login' button is clicked.
 * initial login, when app opens (test,test)
 */
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

/**
 * Handles the event when the 'Playlists' button is clicked.
 * gets the vector of playlist pulled from spotify
 */
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


/**
 * Handles the event when the 'Get Coordinates' button is clicked.
 * gets the coordinates of current location
 */

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

/**
 * Handles the event when the 'Create Location' button is clicked.
 * creates new location in specified file
 */
void LoginWindow::on_pushButton_createLocation_clicked()
{
    //dies if the methods not here idk why
    //leave empty

}

/**
 * Handles the event when the 'Edit Location' button is clicked.
 * Allows for a location to be edited
 */
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


}


void LoginWindow::on_pushButton_refreshLocation_clicked()
{
    gAPI->getLocation();
    location::Location newLoc(gAPI->getLocationLat(), gAPI->getLocationLng());
    QString message = "LAT: " + QString::number(gAPI->getLocationLat());
    QMessageBox::information(this, "Error!", message);
    Playlist::playlist p = checkMapChange(newLoc);
    if (p.getPlaylistName() != "dummy") {
        spotifyAPI->playSong(&p);
    }



}



void LoginWindow::on_pushButton_clicked()
{
    bool ok;
    double latitude = QInputDialog::getDouble(nullptr, "Input", "Enter latitude:", 0, -1000, 1000, 6, &ok);
    double longitude = QInputDialog::getDouble(nullptr, "Input", "Enter longitude:", 0, -1000, 1000, 6, &ok);
    //gAPI->getLocation();
    location::Location newLoc(latitude, longitude);
    //QString message = "LAT: " + QString::number(gAPI->getLocationLat());
    //QMessageBox::information(this, "Error!", message);
    Playlist::playlist p = checkMapChange(newLoc);
    if (p.getPlaylistName() != "dummy") {
        spotifyAPI->playSong(&p);
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




}


void LoginWindow::on_pushButton_refreshLocation_clicked()
{
    gAPI->getLocation();
    location::Location newLoc(gAPI->getLocationLat(), gAPI->getLocationLng());
    QString message = "LAT: " + QString::number(gAPI->getLocationLat());
    QMessageBox::information(this, "Error!", message);
    Playlist::playlist p = checkMapChange(newLoc);
    if (p.getPlaylistName() != "dummy") {
        spotifyAPI->playSong(&p);
    }



}




void LoginWindow::on_pushButton_clicked()
{
    bool ok;
    double latitude = QInputDialog::getDouble(nullptr, "Input", "Enter latitude:", 0, -1000, 1000, 6, &ok);
    double longitude = QInputDialog::getDouble(nullptr, "Input", "Enter longitude:", 0, -1000, 1000, 6, &ok);
    //gAPI->getLocation();
    location::Location newLoc(latitude, longitude);
    //QString message = "LAT: " + QString::number(gAPI->getLocationLat());
    //QMessageBox::information(this, "Error!", message);
    Playlist::playlist p = checkMapChange(newLoc);
    if (p.getPlaylistName() != "dummy") {
        spotifyAPI->playSong(&p);
    }
}

