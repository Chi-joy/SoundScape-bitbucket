/**

@file selectplaylist.h
@brief Contains the selectPlaylist class which handles selecting and saving playlists
@author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
*/

#ifndef SELECTPLAYLIST_H
#define SELECTPLAYLIST_H

#include <QStringListModel>
#include <QDialog>
#include <QVariant>

QT_BEGIN_NAMESPACE
namespace Ui { class selectPlaylist; }
QT_END_NAMESPACE

/**
@brief The selectPlaylist class handles the selection and saving of playlists
*/
class selectPlaylist : public QDialog
{
    Q_OBJECT

public:
/**
* @brief Constructor for the selectPlaylist class
* @param parent The parent QWidget of this dialog
*/
    selectPlaylist(QWidget *parent = nullptr);
/**
* @brief Destructor for the selectPlaylist class
*/
    ~selectPlaylist();

public slots:
    /**
    * @brief Slot to open the playlist selection dialog
    */
    void open_playlistSelection();

private slots:
    /**
    * @brief Slot for when the "Enter" button is clicked on the playlist map dialog
    */
    void on_buttonBox_playlistMapEnter_accepted();
	/**
     * @brief Slot for when the "Save" button is clicked on the playlist map dialog
     */
    void on_pushButton_savePlaylistMap_clicked();

private:
    Ui::selectPlaylist *ui;
};
#endif // SELECTPLAYLIST_H
