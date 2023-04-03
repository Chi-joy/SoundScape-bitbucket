#include "selectplaylistwidget.h"
#include "MetaData.h"
#include "savelocation.h"
#include "ui_selectplaylistwidget.h"
#include <QStringListModel>

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

void selectPlaylistWidget::setPlaylistVector(std::vector<Playlist::playlist> pV) {
    this->playlistVector = pV;
}

selectPlaylistWidget::~selectPlaylistWidget()
{
    delete ui;
}

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

//helper method to check if placing a new zone will overlap with the others
bool checkOverlap(location::Location targetLocation ){

    Metadata m = Metadata();
    std::vector<PlaylistMap> pV = m.buildData("mdata.csv");
    int size = pV.size();

    //iterate through every existing zone and check for overlaps within the circumference
    for (int i = 0; i < size; i++){
        PlaylistMap it = pV.at(i);
        location::Location playlistLoc = it.getLocation();

        double latDiffSquared = (playlistLoc.getLat() - targetLocation.getLat()) * (playlistLoc.getLat() - targetLocation.getLat());
        double lngDiffSquared = (playlistLoc.getLng() - targetLocation.getLng()) * (playlistLoc.getLng() - targetLocation.getLng());

        if ( sqrt(latDiffSquared + lngDiffSquared) <= 3400){
            //if an overlap exists return false to indicate failure
            return false;
        }
    }
    //if you don't find an overlap, return true
    return true;
}


void selectPlaylistWidget::on_pushButton_addLocation_clicked()
{
    saveLocation * saveLocationN = new saveLocation(this);
    saveLocationN->exec();


    //connect(ui->pushButton_createLocation, &QPushButton::clicked, saveLocationN, &saveLocation::exec);
}


void selectPlaylistWidget::on_pushButton_cancel_clicked()
{
    close();
}

