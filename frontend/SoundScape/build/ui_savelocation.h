/********************************************************************************
** Form generated from reading UI file 'savelocation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVELOCATION_H
#define UI_SAVELOCATION_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_saveLocation
{
public:
    QQuickWidget *quickWidget_map_saveLocation;
    QLabel *label;
    QPushButton *pushButton_saveNewLocation;
    QPushButton *pushButton_cancel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_locationName;

    void setupUi(QDialog *saveLocation)
    {
        if (saveLocation->objectName().isEmpty())
            saveLocation->setObjectName(QStringLiteral("saveLocation"));
        saveLocation->resize(452, 416);
        quickWidget_map_saveLocation = new QQuickWidget(saveLocation);
        quickWidget_map_saveLocation->setObjectName(QStringLiteral("quickWidget_map_saveLocation"));
        quickWidget_map_saveLocation->setGeometry(QRect(10, 80, 431, 291));
        quickWidget_map_saveLocation->setResizeMode(QQuickWidget::SizeRootObjectToView);
        label = new QLabel(saveLocation);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 311, 20));
        pushButton_saveNewLocation = new QPushButton(saveLocation);
        pushButton_saveNewLocation->setObjectName(QStringLiteral("pushButton_saveNewLocation"));
        pushButton_saveNewLocation->setGeometry(QRect(270, 380, 171, 32));
        pushButton_saveNewLocation->setStyleSheet(QLatin1String("background-color:rgb(30,215,96);\n"
"color:black;\n"
"border-style: outset;\n"
"border-radius: 10px;"));
        pushButton_cancel = new QPushButton(saveLocation);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(170, 380, 91, 32));
        pushButton_cancel->setStyleSheet(QLatin1String("background-color:rgb(184, 184, 184);\n"
"color:black;\n"
"border-style: outset;\n"
"border-radius: 10px;"));
        widget = new QWidget(saveLocation);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 421, 23));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_locationName = new QLineEdit(widget);
        lineEdit_locationName->setObjectName(QStringLiteral("lineEdit_locationName"));

        horizontalLayout->addWidget(lineEdit_locationName);


        retranslateUi(saveLocation);

        QMetaObject::connectSlotsByName(saveLocation);
    } // setupUi

    void retranslateUi(QDialog *saveLocation)
    {
        saveLocation->setWindowTitle(QApplication::translate("saveLocation", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("saveLocation", "Click the map to create a Zone:", Q_NULLPTR));
        pushButton_saveNewLocation->setText(QApplication::translate("saveLocation", "Save New Location!", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("saveLocation", "Cancel", Q_NULLPTR));
        label_2->setText(QApplication::translate("saveLocation", "Location Name:", Q_NULLPTR));
        lineEdit_locationName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class saveLocation: public Ui_saveLocation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVELOCATION_H
