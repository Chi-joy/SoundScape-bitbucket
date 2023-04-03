#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "PlaylistMap.h"
#include "playlist.h"
#include "worker.h"

#include <QMainWindow>
#include <QVariant>
#include <QThread>
#include <QEventLoop>


QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    bool isLoggedIn;

    ~LoginWindow();

public slots:
    void callPlaySong();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_playlists_clicked();

    void on_pushButton_coor_clicked();

    void on_pushButton_createLocation_clicked();

    void on_pushButton_editLocation_clicked();

    void on_pushButton_createPMap_clicked();

    void setLists();

    void on_pushButton_refreshLists_clicked();
    void handleWorkerMessage(QString s);
    //Playlist::playlist checkMapChange(location::Location currentLocation);
    //void random_number_generator(WorkerThread* workerThread);




    void on_pushButton_editPMaps_clicked();

    void on_pushButton_refreshLocation_clicked();

signals:
    void saveLocationClicked();
    void panToLocation();
    void startWorkerThread();
    void stopWorkerThread();

private:
    Ui::LoginWindow *ui;
    void createSpotifyObject();
    void getLocations();
    //PlaylistMap * currentMapp;

    //MyWorker *worker;
    Playlist::playlist playlistPlaying;

};
#endif // LOGINWINDOW_H
