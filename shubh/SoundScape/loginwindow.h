/**

@file LoginWindow.h
@brief Header file for LoginWindow class, which represents the main window of the application.
*/

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

/**

@brief The LoginWindow class represents the main window of the application.
*/
class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
    * @brief Constructs a LoginWindow object.
    *
    * @param parent the parent widget
    */
    LoginWindow(QWidget *parent = nullptr);
    /**
     * @brief A flag indicating whether the user is logged in to Spotify or not.
     */
    bool isLoggedIn;
	/**
     * @brief Destructs a LoginWindow object.
     */
    ~LoginWindow();

public slots:
	/**
    * @brief Slot to call the playSong function.
    */
    void callPlaySong();

private slots:
	/**
    * @brief Slot to handle the login button being clicked.
    */
    void on_pushButton_login_clicked();
	
    /**
     * @brief Slot to handle the playlists button being clicked.
     */
    void on_pushButton_playlists_clicked();
    
	/**
     * @brief Slot to handle the coordinates button being clicked.
     */
    void on_pushButton_coor_clicked();

	/**
     * @brief Slot to handle the create location button being clicked.
     */
    void on_pushButton_createLocation_clicked();

	/**
     * @brief Slot to handle the edit location button being clicked.
     */
    void on_pushButton_editLocation_clicked();

	/**
     * @brief Slot to handle the create playlist map button being clicked.
     */
    void on_pushButton_createPMap_clicked();
	
    /**
     * @brief Slot to set the list of playlists.
     */
    void setLists();

    /**
     * @brief Slot to handle the refresh playlists button being clicked.
     */
    void on_pushButton_refreshLists_clicked();
    /**
     * @brief Slot to handle the worker message being received.
     *
     * @param s the message received by the worker
     */
    void handleWorkerMessage(QString s);
    //Playlist::playlist checkMapChange(location::Location currentLocation);
    //void random_number_generator(WorkerThread* workerThread);



	/**
     * @brief Slot to handle the edit playlist maps button being clicked.
     */
    void on_pushButton_editPMaps_clicked();
	
    /**
     * @brief Slot to handle the refresh locations button being clicked.
     */
    void on_pushButton_refreshLocation_clicked();

	/**
     * @brief Slot to handle the button being clicked.
     */
    void on_pushButton_clicked();

signals:
    /**
    * @brief Signal emitted when the save location button is clicked.
    */
    void saveLocationClicked();
    /**
     * @brief Signal emitted when the map should pan to the location.
     */
    void panToLocation();
    /**
     * @brief Signal emitted when the worker thread should start.
     */
    void startWorkerThread();
    /**
     * @brief Signal emitted when the worker thread should stop.
     */
    void stopWorkerThread();

private:
    Ui::LoginWindow *ui;
    /**
   * @brief Creates a Spotify object.
   */
    void createSpotifyObject();
    void getLocations();
    //PlaylistMap * currentMapp;

    //MyWorker *worker;
    Playlist::playlist playlistPlaying;

};
#endif // LOGINWINDOW_H
