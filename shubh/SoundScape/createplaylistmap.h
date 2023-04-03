/**
 * @file createplaylistmap.h
 * @brief Header file for the createPlaylistMap class.
 * 
 * This file contains the declaration of the createPlaylistMap class, which
 * is a QDialog that allows the user to create a new playlist map.
 * 
 * The createPlaylistMap class is defined in this header file, and it inherits
 * from the QDialog class provided by the Qt framework.
 * 
 * @author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano 
 */

#ifndef CREATEPLAYLISTMAP_H
#define CREATEPLAYLISTMAP_H

#include <QDialog>

namespace Ui {
class createPlaylistMap;
}

class createPlaylistMap : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new createPlaylistMap object.
     * 
     * This constructor creates a new createPlaylistMap object with the given
     * parent widget. It also initializes the user interface using the Ui::createPlaylistMap
     * class.
     * 
     * @param parent The parent widget.
     */
    explicit createPlaylistMap(QWidget *parent = nullptr);

    /**
     * @brief Destroys the createPlaylistMap object.
     * 
     * This destructor is responsible for cleaning up the createPlaylistMap object
     * and releasing any resources that it may have acquired during its lifetime.
     * It deletes the user interface object that was created in the constructor.
     */
    ~createPlaylistMap();

private:
    Ui::createPlaylistMap *ui;
};

#endif // CREATEPLAYLISTMAP_H

