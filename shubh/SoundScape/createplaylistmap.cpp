#include "createplaylistmap.h"
#include "ui_createplaylistmap.h"

createPlaylistMap::createPlaylistMap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createPlaylistMap)
{
    ui->setupUi(this);
}

createPlaylistMap::~createPlaylistMap()
{
    delete ui;
}
