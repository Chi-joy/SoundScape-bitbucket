#include "selectplaylistwidget.h"
#include "savelocation.h"
#include "ui_selectplaylistwidget.h"

selectPlaylistWidget::selectPlaylistWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectPlaylistWidget)
{
    ui->setupUi(this);
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

