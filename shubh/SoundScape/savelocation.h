#ifndef SAVELOCATION_H
#define SAVELOCATION_H

#include <QDialog>

namespace Ui {
class saveLocation;
}

class saveLocation : public QDialog
{
    Q_OBJECT

public:
    explicit saveLocation(QWidget *parent = nullptr);
    void setCoordinates(double latitude, double longitude);
    ~saveLocation();

private slots:
    void on_buttonBox_accepted();


private:
    Ui::saveLocation *ui;
};

#endif // SAVELOCATION_H
