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

signals:
    void setCenter(double, double);
private:
    Ui::LoginWindow *ui;
    void createSpotifyObject();
};
#endif // LOGINWINDOW_H
