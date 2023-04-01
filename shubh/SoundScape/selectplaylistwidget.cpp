#include "selectplaylistwidget.h"
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

