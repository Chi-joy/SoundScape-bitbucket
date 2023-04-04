/**
 * @file selectplaylistwidget.cpp
 * @brief Implementation of the selectplaylistwidget class.
 * 
 * This file contains the implementation of the selectplaylistwidget class, which
 * is the select playlist widget for the UI.
 * 
 * @author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
 */

#include "selectplaylistwidget.h"
#include "MetaData.h"
#include "savelocation.h"
#include "ui_selectplaylistwidget.h"
#include <QStringListModel>

/**
 * @brief Constructs a new selectPlaylistWidget object with the given parent.
 *
 * This constructor creates a new selectPlaylistWidget object and initializes its UI.
 *
 * @param parent the parent widget of the new selectPlaylistWidget object.
 */
selectPlaylistWidget::selectPlaylistWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectPlaylistWidget)
{
    ui->setupUi(this);

    Metadata m = Metadata();
    QStringListModel *model = new QStringListModel(this);

    std::vector<location::Location> locationVector = m.buildDataLocation("locations.csv");

    int size = locationVector.size();
    QStringList locationNames;

    for (int i = 0; i < size; i++) {
        location::Location tempLocation = locationVector[i];
        locationNames.append(tempLocation.getName());
    }

    model->setStringList(locationNames);
    ui->listView_locations->setModel(model);
}

/**
 * @brief Sets the fields of the selectPlaylistWidget based on the given PlaylistMap.
 *
 * This function sets the location and playlist fields of the selectPlaylistWidget based
 * on the values in the given PlaylistMap object.
 *
 * @param pM The PlaylistMap object containing the location and playlist to be selected.
 */
void selectPlaylistWidget::setFields(PlaylistMap pM) {

    int size = ui->listView_locations->model()->rowCount();
    for (int i = 0; i < size; i++) {
        QModelIndex index = ui->listView_locations->model()->index(i, 0);
        QString item = ui->listView_locations->model()->data(index, Qt::DisplayRole).toString();
        if (item == pM.getLocation().getName()) {
            ui->listView_locations->setCurrentIndex(index);
        }
    }

    int s = ui->listView_playlists->model()->rowCount();
    for (int i = 0; i < s; i++) {
        QModelIndex index = ui->listView_playlists->model()->index(i, 0);
        QString item = ui->listView_playlists->model()->data(index, Qt::DisplayRole).toString();
        if (item == pM.getLocation().getName()) {
            ui->listView_playlists->setCurrentIndex(index);
        }
    }
}

/**
 * @brief Sets the playlist vector of the selectPlaylistWidget to the given vector.
 *
 * This function sets the playlist vector of the selectPlaylistWidget to the given vector
 * of Playlist objects.
 *
 * @param pV The vector of Playlist objects to be set as the playlist vector.
 */
void selectPlaylistWidget::setPlaylistVector(std::vector<Playlist::playlist> pV) {
    this->playlistVector = pV;
}

/**
 * @brief Destructor for the selectPlaylistWidget class.
 *
 * This function is the destructor for the selectPlaylistWidget class. It deletes the
 * ui object used by the widget.
 */
selectPlaylistWidget::~selectPlaylistWidget()
{
    delete ui;
}

/**
 * @brief Slot function for the pushButton_savePlaylistMap button.
 *
 * This function is the slot function for the pushButton_savePlaylistMap button. When the button
 * is clicked, this function creates a new PlaylistMap object with the currently selected location
 * and playlist, and then saves this new object to the "mdata.csv" file.
 */
void selectPlaylistWidget::on_pushButton_savePlaylistMap_clicked()
{
    QModelIndex index = ui->listView_locations->currentIndex();
    QString locationName = index.data(Qt::DisplayRole).toString();
    Playlist::playlist playlistObj = this->playlistVector.at(index.row());

    Metadata m = Metadata();

    std::vector<location::Location> lV = m.buildDataLocation("locations.csv");
    location::Location locationObj;
    int size = lV.size();
    for (int i = 0; i < size; i++) {
        if (lV.at(i).getName() == locationName) {
            locationObj = lV.at(i);
        }
    }

    PlaylistMap pM(locationObj, playlistObj);


    std::vector<PlaylistMap> pV = m.buildData("mdata.csv");
    pV.push_back(pM);
    m.writeData(pV,"mdata.csv");
}

/**
 * @brief Slot function for the pushButton_addLocation button.
 *
 * This function is the slot function for the pushButton_addLocation button. When the button
 * is clicked, this function opens the saveLocation dialog and waits for the user to input a new location.
 */
void selectPlaylistWidget::on_pushButton_addLocation_clicked()
{
    saveLocation * saveLocationN = new saveLocation(this);
    saveLocationN->exec();


    //connect(ui->pushButton_createLocation, &QPushButton::clicked, saveLocationN, &saveLocation::exec);
}

/**
 * @brief Slot function for the pushButton_cancel button.
 *
 * This function is the slot function for the pushButton_cancel button. When the button
 * is clicked, this function closes the selectPlaylistWidget window.
 */
void selectPlaylistWidget::on_pushButton_cancel_clicked()
{
    close();
}

