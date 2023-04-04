/**
 * @file savelocation.h
 * @brief Header file of the savelocation class.
 * 
 * This file contains the declaration of the savelocation class, which
 * is used to save a location for a user.
 * 
 * @author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
 */

#ifndef SAVELOCATION_H
#define SAVELOCATION_H

#include "MetaData.h"
#include <QDialog>

namespace Ui {
class saveLocation;
}

class saveLocation : public QDialog
{
    Q_OBJECT

public:
    double markerlatitude;
    double markerlongitude;
    /**
 	* @brief Constructs a new saveLocation dialog.
 	*
 	* @param parent The parent widget of the dialog.
 	*/
    explicit saveLocation(QWidget *parent = nullptr);
    
    /**
 	* @brief The destructor of the saveLocation class.
 	*
 	* This destructor deletes the user interface object of the saveLocation class.
 	* It is called when an instance of the class is destroyed, and it ensures that
 	* any memory allocated by the user interface object is properly freed.
 	*/
    ~saveLocation();

public slots:
	/**
 	* @brief Slot function that sets the member variables markerlatitude and markerlongitude to the
 	* values of the signal, which represent the latitude and longitude of a marker on a map.
 	* The function can be used to update the position of a marker on a map based on the
 	* values of the signal.
 	*
 	* @param number1 The latitude of the marker.
 	* @param number2 The longitude of the marker.
 	*/
    void handleMySignal(double lat, double lng);

private slots:
	/**
 	* @brief Function that is called when the "Cancel" button is clicked 
 	* in the user interface of the saveLocation class. The function rejects the
 	* dialog, which closes the dialog without saving any changes. This function
 	* can be used to cancel any pending changes to the dialog and close it.
 	*/
    void on_pushButton_cancel_clicked();
	
    /**
 	* @brief Slot function that is called when the "Save" button is clicked in the
 	* user interface of the saveLocation class to create a new location.
 	*
 	* The function reads the name of the new location from a text input field, and checks if a valid location has
 	* been selected on the map. If the inputs are valid and the new location does not overlap
 	* with any existing locations, it is added to a CSV file containing all the saved locations,
 	* and the dialog is closed. If the new location overlaps with an existing location, an error
 	* message is displayed and the location is not saved.
 	*
 	*/
    void on_pushButton_saveNewLocation_clicked();
    
    /**
 	* @brief Checks if placing a new zone will overlap with existing zones.
 	* This is a helper method.
 	*
 	* @param targetLocation The location of the new zone.
 	* @return true if the new zone will overlap with existing zones, false otherwise.
 	*/
    bool checkOverlap(location::Location targetLocation );

	/**
 	* @brief Converts degrees to radians.
 	*
 	* @param degrees The degrees to be converted to radians.
 	*/
    double toRadians(double degrees);
    
    /**
 	* @brief Calculates the distance between two locations.
 	*
 	* @param currentLocation The current location.
 	* @param playlistLocation The location of a playlist item.
	 * @return The distance between the two locations in kilometers.
	 */
    double distanceCheck(location::Location currentLocation, location::Location playlistLocation);

private:
    Ui::saveLocation *ui;
};

#endif // SAVELOCATION_H
