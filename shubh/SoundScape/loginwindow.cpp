#include "loginwindow.h"
#include "spotifyapi.h"
#include "ui_loginwindow.h"
#include <QDesktopServices>
#include <QMessageBox>
#include <QStringListModel>

    SpotifyAPI * spotifyAPI;
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

   // ui->groupBox_login->hide();
    connect(ui->pushButton_spotify, &QPushButton::released, this, &LoginWindow::createSpotifyObject);
    ui->pushButton_spotify->hide();
    ui->pushButton_playlists->hide();
    ui->groupBox_playlists->hide();



}

void LoginWindow::createSpotifyObject() {

    spotifyAPI = new SpotifyAPI();
    spotifyAPI->authenticate();
    ui->pushButton_spotify->hide();
    ui->pushButton_playlists->show();

}

LoginWindow::~LoginWindow()
{
   // delete this->spotifyAuth;
    delete ui;
}


void LoginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username != "test" || password != "test") {
        QMessageBox::information(this, "error", "wrong username or pass");
    } else {
        QMessageBox::information(this, "success", "nice");
        ui->groupBox_login->hide();
        ui->pushButton_spotify->show();


    }
}


void LoginWindow::on_pushButton_playlists_clicked()
{


    QStringListModel *model = new QStringListModel(this);
    ui->pushButton_playlists->hide();
    ui->groupBox_playlists->show();
    std::vector<Playlist::playlist> playlistVector = spotifyAPI->getVector();
    int size = playlistVector.size();
    QStringList playlistNames;

    for (int i = 0; i < size; i++) {
        Playlist::playlist tempPlaylist = playlistVector[i];
        playlistNames.append(tempPlaylist.getPlaylistName());
    }

    model->setStringList(playlistNames);
    ui->listView_playlists->setModel(model);

}

