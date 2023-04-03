#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "Location.h"
#include "pingingBackground.h"
#include <QMainWindow>
#include <QVariant>
#include <QThread>

class MyWorker : public QObject
{
    Q_OBJECT

signals:
    void messageReceived(Playlist::playlist &p);

public slots:
    void doWork() {
        pingingBackground ping;
        while (true) {
            // Do some work in the background
            location::Location curLoc = ping.pingLocation();
            Playlist::playlist p = ping.checkMapChange(curLoc);
            if (p.getPlaylistName() != "dummy") {
                emit messageReceived(p);
            }


            QThread::msleep(10*1000); // Sleep for 10 seconds (in milliseconds)
        }
    }
};

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

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_playlists_clicked();

    void on_pushButton_coor_clicked();

    void on_pushButton_createLocation_clicked();

    void on_pushButton_editLocation_clicked();

    void on_pushButton_createPMap_clicked();

    void setLists();

    void on_pushButton_refreshLists_clicked();
    void handleWorkerMessage(Playlist::playlist &p);



signals:
    void saveLocationClicked();
    void panToLocation();
    void startWorkerThread();
    void stopWorkerThread();

private:
    Ui::LoginWindow *ui;
    void createSpotifyObject();
    void getLocations();
    QThread *workerThread;
    MyWorker *worker;

};
#endif // LOGINWINDOW_H
