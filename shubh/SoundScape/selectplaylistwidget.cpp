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

