#ifndef SELECTPLAYLISTWIDGET_H
#define SELECTPLAYLISTWIDGET_H

#include <QWidget>
#include "Location.h"
#include "playlist.h"

namespace Ui {
class selectPlaylistWidget;
}

class selectPlaylistWidget : public QWidget
{
    Q_OBJECT

public:
    explicit selectPlaylistWidget(QWidget *parent = nullptr);
    ~selectPlaylistWidget();
    Ui::selectPlaylistWidget *ui;
    std::vector<Playlist::playlist> playlistVector;
    void setPlaylistVector(std::vector<Playlist::playlist> pV);

private slots:
    void on_pushButton_savePlaylistMap_clicked();

    void on_pushButton_addLocation_clicked();

    void on_pushButton_cancel_clicked();

    //bool checkOverlap(location::Location targetLocation );



private:

};

#endif // SELECTPLAYLISTWIDGET_H
