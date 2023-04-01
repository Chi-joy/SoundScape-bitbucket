#include "savelocation.h"
#include "ui_savelocation.h"

saveLocation::saveLocation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saveLocation)
{
    ui->setupUi(this);
    ui->quickWidget_map_saveLocation->setSource(QUrl(QStringLiteral("qrc:/newLoc.qml")));
}

saveLocation::~saveLocation()
{
    delete ui;
}

void saveLocation::on_buttonBox_accepted()
{

}

