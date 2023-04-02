#ifndef SELECTPLAYLISTWIDGET_H
#define SELECTPLAYLISTWIDGET_H

#include <QWidget>

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

private slots:
    void on_pushButton_savePlaylistMap_clicked();

    void on_pushButton_addLocation_clicked();

    void on_pushButton_cancel_clicked();

private:

};

#endif // SELECTPLAYLISTWIDGET_H
