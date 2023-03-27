#ifndef SELECTPLAYLIST_H
#define SELECTPLAYLIST_H

#include <QDialog>

namespace Ui {
class selectPlaylist;
}

class selectPlaylist : public QDialog
{
    Q_OBJECT

public:
    explicit selectPlaylist(QWidget *parent = nullptr);
    ~selectPlaylist();

public slots:
    void open_playlistSelection();

private:
    Ui::selectPlaylist *ui;
};
#endif // SELECTPLAYLIST_H
