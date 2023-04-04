/**
 * @file selectplaylistwidget.h
 * @brief Header file of the selectplaylistwidget class.
 * 
 * This file contains the declaration of the selectplaylistwidget class, which
 * is the select playlist widget for the UI.
 * 
 * @author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
 */

#ifndef SELECTPLAYLISTWIDGET_H
#define SELECTPLAYLISTWIDGET_H

#include <QWidget>
#include "PlaylistMap.h"

namespace Ui {
class selectPlaylistWidget;
}

class selectPlaylistWidget : public QWidget
{
    Q_OBJECT

public:
	Ui::selectPlaylistWidget *ui;
    std::vector<Playlist::playlist> playlistVector;
    
    /**
 	* @brief Constructs a new selectPlaylistWidget object with the given parent.
 	*
 	* This constructor creates a new selectPlaylistWidget object and initializes its UI.
 	*
 	* @param parent the parent widget of the new selectPlaylistWidget object.
 	*/
    explicit selectPlaylistWidget(QWidget *parent = nullptr);
    
    /**
 	* @brief Destructor for the selectPlaylistWidget class.
 	*
 	* This function is the destructor for the selectPlaylistWidget class. It deletes the
 	* ui object used by the widget.
 	*/
    ~selectPlaylistWidget();
    
    /**
	* @brief Sets the playlist vector of the selectPlaylistWidget to the given vector.
	*
 	* This function sets the playlist vector of the selectPlaylistWidget to the given vector
 	* of Playlist objects.
 	*
 	* @param pV The vector of Playlist objects to be set as the playlist vector.
 	*/
    void setPlaylistVector(std::vector<Playlist::playlist> pV);
    
    /**
 	* @brief Sets the fields of the selectPlaylistWidget based on the given PlaylistMap.
 	*
 	* This function sets the location and playlist fields of the selectPlaylistWidget based
 	* on the values in the given PlaylistMap object.
 	*
 	* @param pM The PlaylistMap object containing the location and playlist to be selected.
 	*/
    void setFields(PlaylistMap pM);

private slots:
	/**
 	* @brief Slot function for the pushButton_savePlaylistMap button.
 	*
 	* This function is the slot function for the pushButton_savePlaylistMap button. When the button
 	* is clicked, this function creates a new PlaylistMap object with the currently selected location
 	* and playlist, and then saves this new object to the "mdata.csv" file.
 	*/
    void on_pushButton_savePlaylistMap_clicked();

	/**
 	* @brief Slot function for the pushButton_addLocation button.
 	*
 	* This function is the slot function for the pushButton_addLocation button. When the button
 	* is clicked, this function opens the saveLocation dialog and waits for the user to input a new location.
 	*/
    void on_pushButton_addLocation_clicked();
	
    /**
 	* @brief Slot function for the pushButton_cancel button.
 	*
 	* This function is the slot function for the pushButton_cancel button. When the button
 	* is clicked, this function closes the selectPlaylistWidget window.
 	*/
    void on_pushButton_cancel_clicked();

private:

};

#endif // SELECTPLAYLISTWIDGET_H
