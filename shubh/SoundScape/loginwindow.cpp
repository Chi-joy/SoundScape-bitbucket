#include "loginwindow.h"
#include "spotifyapi.h"
#include "ui_loginwindow.h"
#include <QDesktopServices>


LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::released, this, &LoginWindow::createSpotifyObject);

}

void LoginWindow::createSpotifyObject() {
    SpotifyAPI * spotifyAPI;
    spotifyAPI = new SpotifyAPI();
    spotifyAPI->authenticate();
}

LoginWindow::~LoginWindow()
{
   // delete this->spotifyAuth;
    delete ui;
}

