/**
 * @file createplaylistmap.cpp
 * @brief Implementation of the createPlaylistMap class.
 * 
 * This file contains the implementation of the createPlaylistMap class, which
 * is a QDialog that allows the user to create a new playlist map.
 * 
 * @author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
 */

#include "createplaylistmap.h"
#include "ui_createplaylistmap.h"

/**
 * @brief Constructs a new createPlaylistMap object.
 * 
 * This constructor creates a new createPlaylistMap object with the given
 * parent widget. It also initializes the user interface using the Ui::createPlaylistMap
 * class.
 * 
 * @param parent The parent widget.
 */
createPlaylistMap::createPlaylistMap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createPlaylistMap)
{
    ui->setupUi(this);
}

/**
 * @brief Destroys the createPlaylistMap object.
 * 
 * This destructor is responsible for cleaning up the createPlaylistMap object
 * and releasing any resources that it may have acquired during its lifetime.
 * It deletes the user interface object that was created in the constructor.
 */
createPlaylistMap::~createPlaylistMap()
{
    delete ui;
} 

