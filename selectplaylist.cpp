#include "selectplaylist.h"
#include "ui_selectplaylist.h"

selectPlaylist::selectPlaylist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectPlaylist)
{
    ui->setupUi(this);
    connect(loginwindow, SIGNAL(playlistPair_clicked()), this, SLOT(open_playlistSelection()));
}

selectPlaylist::~selectPlaylist()
{
    delete ui;
}

void selectPlaylist::open_playlistSelection()
{
    // create new instance of select playlist ui
    selectPlaylist *newSelectedPlaylist = new selectPlaylist();

    //display new form
    newSelectedPlaylist->show();
}
