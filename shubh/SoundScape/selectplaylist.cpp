/**
 * @file selectplaylist.cpp
 * @brief Implementation of the selectplaylist class.
 * 
 * This file contains the implementation of the selectplaylist class, which
 * is used for selecting a playlist.
 * 
 * @author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
 */

#include "selectplaylist.h"
#include "ui_selectplaylist.h"

/**
 * @brief Constructs a new selectPlaylist object.
 *
 * This constructor creates a new QDialog object with the specified parent widget and sets up the user
 * interface. It also sets the selection mode of the playlist and location list views to SingleSelection.
 *
 * @param parent The parent QWidget of the dialog.
 */
selectPlaylist::selectPlaylist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectPlaylist)
{
    ui->setupUi(this);
    ui->listView_playlists->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->listView_locations->setSelectionMode(QAbstractItemView::SingleSelection);
}

/**
 * @brief Destroys the selectPlaylist object and frees any allocated memory.
 *
 * This destructor deletes the user interface object ui and frees any resources that were
 * allocated for the selectPlaylist object.
 */
selectPlaylist::~selectPlaylist()
{
    delete ui;
}

/**
 * @brief Opens the playlist selection dialog.
 *
 * This function creates a new instance of the selectPlaylist dialog and displays it to the user.
 * The user can then select a playlist and location from the dialog and return the selected values to the
 * calling function.
 */
void selectPlaylist::open_playlistSelection()
{
    // create new instance of select playlist ui
    selectPlaylist *newSelectedPlaylist = new selectPlaylist();

    //display new form
    newSelectedPlaylist->show();
}

/**
 * @brief Saves the selected playlist and location to a map.
 *
 * This function retrieves the currently selected playlist from the list view and saves it to a map
 * with the selected location. The saved map can be used by the calling function to perform further actions
 * with the selected playlist and location.
 */
void selectPlaylist::on_pushButton_savePlaylistMap_clicked()
{
    QItemSelectionModel *playlistModel = ui->listView_playlists->selectionModel();
    QModelIndexList selectedIndexes = playlistModel->selectedIndexes();
    QModelIndex playlistIndex = selectedIndexes.first();
    QString data = playlistIndex.data(Qt::DisplayRole).toString();

}

