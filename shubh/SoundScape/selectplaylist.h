#ifndef SELECTPLAYLIST_H
#define SELECTPLAYLIST_H

#include <QStringListModel>
#include <QDialog>
#include <QVariant>

QT_BEGIN_NAMESPACE
namespace Ui { class selectPlaylist; }
QT_END_NAMESPACE

class selectPlaylist : public QDialog
{
    Q_OBJECT

public:
    selectPlaylist(QWidget *parent = nullptr);
    ~selectPlaylist();

public slots:
    void open_playlistSelection();

private slots:
    void on_buttonBox_playlistMapEnter_accepted();

    void on_pushButton_savePlaylistMap_clicked();

private:
    Ui::selectPlaylist *ui;
};
#endif // SELECTPLAYLIST_H
