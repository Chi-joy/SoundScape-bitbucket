#include "loginwindow.h"
#include "spotifyapi.h"
#include "ui_loginwindow.h"
#include <QDesktopServices>
#include <QMessageBox>


LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

   // ui->groupBox_login->hide();
    connect(ui->pushButton_spotify, &QPushButton::released, this, &LoginWindow::createSpotifyObject);
    ui->pushButton_spotify->hide();



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

