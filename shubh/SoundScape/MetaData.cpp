/**
 * @file Metadata.cpp
 * @brief Definition of Metadata class methods
 */

#include "Metadata.h"
#include <QCoreApplication>
using namespace std;
using namespace Playlist;
using namespace location;

/**
 * @brief Default constructor for Metadata class
 */
Metadata::Metadata()
{
    //ctor
}

/**
 * @brief Builds a vector of PlaylistMap objects from a CSV file
 * @param fname Name of the CSV file to read from
 * @return A vector of PlaylistMap objects
 */
vector<PlaylistMap> Metadata::buildData(string fname){
    vector<PlaylistMap> objects;
    qDebug() << "Current working directory:" << QDir::currentPath();
    QDir directory(QDir::currentPath());
    QFileInfoList fileList = directory.entryInfoList(QDir::Files);

    foreach (QFileInfo fileInfo, fileList) {
        qDebug() << fileInfo.fileName();
    }
    QString filename = QString::fromStdString(fname);
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << filename;
        //return objects;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        qDebug() << fields;
        bool hasP = true;
//        if(fields.at(6).toStdString().compare("T")!=0){
//            hasP=false;
//        }
        playlist p = playlist(fields.at(3),fields.at(4),fields.at(5),hasP);
        Location loc = Location(fields.at(2),stod(fields.at(0).toStdString()),(stod(fields.at(1).toStdString())));
        PlaylistMap pmap = PlaylistMap(loc,p);
        objects.push_back(pmap);
    }

    file.close();

    return objects;
}

/**
 * @brief Writes a vector of PlaylistMap objects to a CSV file
 * @param data A vector of PlaylistMap objects to write
 * @param filename Name of the file to write to
 * @return True if the write operation was successful, false otherwise
 */
bool Metadata::writeData(vector<PlaylistMap> data, string filename){
    std::ofstream outfile(filename);
    for (PlaylistMap& obj : data) {
        outfile << obj.getLocation().getLat() << "," << obj.getLocation().getLng() << "," << obj.getLocation().getName().toStdString() << "," << obj.getPlaylist().getPlaylistName().toStdString() << "," << obj.getPlaylist().getPlaylistURI().toStdString() << "," << obj.getPlaylist().getPlaylistCoverURI().toStdString() << "," << "T\n"; // write data row
    }
    outfile.close();
    std::cout << "CSV file \"" << filename << "\" was written successfully." << std::endl;
    return true;

}

/**
 * @brief Appends a vector of PlaylistMap objects to an existing CSV file
 * @param data A vector of PlaylistMap objects to append
 * @param filename Name of the file to append to
 * @return True if the append operation was successful, false otherwise
 */
bool Metadata::appendData(vector<PlaylistMap> data, string filename){
    std::ofstream outfile(filename, std::ios_base::app);
    for (PlaylistMap& obj : data) {
        //outfile << obj.getLocation().getLat() << "," << obj.getLocation().getLng() << "," << obj.getLocation().getName().toStdString() << "," << obj.getPlaylist().getPlaylistName().toStdString() << "," << obj.getPlaylist().getPlaylistURI().toStdString() << "," << obj.getPlaylist().getPlaylistCoverURI().toStdString() << "," << "T\n"; // write data row
    }
    outfile.close();
    std::cout << "CSV file \"" << filename << "\" was written successfully." << std::endl;
    return true;

}

/**

@brief Build a vector of Location objects from a file

@param fname The name of the file to read from

@return A vector of Location objects
*/
vector<Location> Metadata::buildDataLocation(string fname){
    vector<Location> objects;
        qDebug() << "Current working directory:" << QDir::currentPath();
    //    QDir directory(QDir::currentPath());
    //    QFileInfoList fileList = directory.entryInfoList(QDir::Files);

    //    foreach (QFileInfo fileInfo, fileList) {
    //        qDebug() << fileInfo.fileName();
    //    }
        QString filename = QCoreApplication::applicationDirPath() + "/" + QString::fromStdString(fname);
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Failed to open file:" << filename;
            //return objects;
        }

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            qDebug() << fields;

            Location loc = Location(fields.at(2),stod(fields.at(0).toStdString()),(stod(fields.at(1).toStdString())));

            objects.push_back(loc);
        }

        file.close();

        return objects;
}

/**

@brief Writes the given data to a CSV file with the given filename in the application directory.
@param data The vector of Location objects to be written to the file.
@param filename The name of the file to write the data to.
@return true if the file was written successfully, false otherwise.
*/
bool Metadata::writeDataLocation(vector<Location> data, string filename){
    QString filepath = QCoreApplication::applicationDirPath() + "/" + QString::fromStdString(filename);
    std::ofstream outfile(filepath.toStdString());
    for (Location& obj : data) {
        outfile << obj.getLat() << "," << obj.getLng() << "," << obj.getName().toStdString() + "\n"; // write data row
    }
    outfile.close();
    std::cout << "CSV file \"" << filename << "\" was written successfully." << std::endl;
    return true;

}



Metadata::~Metadata()
{
    //dtor
}
