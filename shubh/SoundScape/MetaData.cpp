#include "Metadata.h"
using namespace std;
using namespace Playlist;

Metadata::Metadata()
{
    //ctor
}

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
        if(fields.at(5).toStdString().compare("T")!=0){
            hasP=false;
        }
        playlist p = playlist(fields.at(2),fields.at(3),fields.at(4),hasP);
        location::Location loc = location::Location(stod(fields.at(0).toStdString()),(stod(fields.at(1).toStdString())));
        PlaylistMap pmap = PlaylistMap(loc,p);
        objects.push_back(pmap);
    }

    file.close();

    return objects;
}
bool Metadata::writeData(vector<PlaylistMap> data, string filename){
    std::ofstream outfile(filename);
    for (PlaylistMap& obj : data) {
        outfile << obj.getLocation().getLat() << "," << obj.getLocation().getLng() << "," << obj.getPlaylist().getPlaylistName().toStdString() << "," << obj.getPlaylist().getPlaylistURI().toStdString() << "," << obj.getPlaylist().getPlaylistCoverURI().toStdString() << "," << "T\n"; // write data row
    }
    outfile.close();
    std::cout << "CSV file \"" << filename << "\" was written successfully." << std::endl;
    return true;

}
bool Metadata::appendData(vector<PlaylistMap> data, string filename){
    std::ofstream outfile(filename, std::ios_base::app);
    for (PlaylistMap& obj : data) {
        outfile << obj.getLocation().getLat() << "," << obj.getLocation().getLng() << "," << obj.getPlaylist().getPlaylistName().toStdString() << "," << obj.getPlaylist().getPlaylistURI().toStdString() << "," << obj.getPlaylist().getPlaylistCoverURI().toStdString() << "," << "T\n"; // write data row
    }
    outfile.close();
    std::cout << "CSV file \"" << filename << "\" was written successfully." << std::endl;
    return true;

}



Metadata::~Metadata()
{
    //dtor
}
