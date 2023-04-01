#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QVariant>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_playlists_clicked();

    void on_pushButton_coor_clicked();

    void on_pushButton_createLocation_clicked();

    void on_pushButton_editLocation_clicked();

    void on_pushButton_createPMap_clicked();

signals:
    void saveLocationClicked();
    void panToLocation();

private:
    Ui::LoginWindow *ui;
    void createSpotifyObject();
    void getLocations();
};
#endif // LOGINWINDOW_H
