#include "selectplaylist.h"
#include "ui_selectplaylist.h"



selectPlaylist::selectPlaylist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectPlaylist)
{
    ui->setupUi(this);
    ui->listView_playlists->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->listView_locations->setSelectionMode(QAbstractItemView::SingleSelection);


    //QStringListModel *model = new QStringListModel(this);
//    std::vector<Playlist::playlist> playlistVector = spotifyAPI->getVector();
//    int size = playlistVector.size();
//    QStringList playlistNames;

//    for (int i = 0; i < size; i++) {
//        Playlist::playlist tempPlaylist = playlistVector[i];
//        playlistNames.append(tempPlaylist.getPlaylistName());
//    }

//    model->setStringList(playlistNames);
//    ui->listView_playlists->setModel(model);
    //connect(loginwindow, SIGNAL(playlistPair_clickedopen_playlistSelection()), this, SLOT(()));
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

void selectPlaylist::on_pushButton_savePlaylistMap_clicked()
{
    QItemSelectionModel *playlistModel = ui->listView_playlists->selectionModel();
    QModelIndexList selectedIndexes = playlistModel->selectedIndexes();
    QModelIndex playlistIndex = selectedIndexes.first();
    QString data = playlistIndex.data(Qt::DisplayRole).toString();

}

