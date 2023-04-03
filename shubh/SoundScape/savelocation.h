#ifndef SAVELOCATION_H
#define SAVELOCATION_H

#include "MetaData.h"
#include <QDialog>

namespace Ui {
class saveLocation;
}

class saveLocation : public QDialog
{
    Q_OBJECT

public:
    double markerlatitude;
    double markerlongitude;
    explicit saveLocation(QWidget *parent = nullptr);
    //void setCoordinates(double latitude, double longitude);
    ~saveLocation();

public slots:
    void handleMySignal(double lat, double lng);

private slots:

    void on_pushButton_cancel_clicked();

    void on_pushButton_saveNewLocation_clicked();
    bool checkOverlap(location::Location targetLocation );

    double toRadians(double degrees);
    double distanceCheck(location::Location currentLocation, location::Location playlistLocation);

private:
    Ui::saveLocation *ui;
};

#endif // SAVELOCATION_H
