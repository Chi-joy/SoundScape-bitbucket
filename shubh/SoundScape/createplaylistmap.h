#ifndef CREATEPLAYLISTMAP_H
#define CREATEPLAYLISTMAP_H

#include <QDialog>

namespace Ui {
class createPlaylistMap;
}

class createPlaylistMap : public QDialog
{
    Q_OBJECT

public:
    explicit createPlaylistMap(QWidget *parent = nullptr);
    ~createPlaylistMap();

private:
    Ui::createPlaylistMap *ui;
};

#endif // CREATEPLAYLISTMAP_H
