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

selectPlaylistWidget::~selectPlaylistWidget()
{
    delete ui;
}

void selectPlaylistWidget::on_pushButton_savePlaylistMap_clicked()
{

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

