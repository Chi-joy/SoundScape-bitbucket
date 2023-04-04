/********************************************************************************
** Form generated from reading UI file 'savelocation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVELOCATION_H
#define UI_SAVELOCATION_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
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
            saveLocation->setObjectName(QString::fromUtf8("saveLocation"));
        saveLocation->resize(452, 416);
        quickWidget_map_saveLocation = new QQuickWidget(saveLocation);
        quickWidget_map_saveLocation->setObjectName(QString::fromUtf8("quickWidget_map_saveLocation"));
        quickWidget_map_saveLocation->setGeometry(QRect(10, 80, 431, 291));
        quickWidget_map_saveLocation->setResizeMode(QQuickWidget::SizeRootObjectToView);
        label = new QLabel(saveLocation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 311, 20));
        pushButton_saveNewLocation = new QPushButton(saveLocation);
        pushButton_saveNewLocation->setObjectName(QString::fromUtf8("pushButton_saveNewLocation"));
        pushButton_saveNewLocation->setGeometry(QRect(270, 380, 171, 32));
        pushButton_saveNewLocation->setStyleSheet(QString::fromUtf8("background-color:rgb(30,215,96);\n"
"color:black;\n"
"border-style: outset;\n"
"border-radius: 10px;"));
        pushButton_cancel = new QPushButton(saveLocation);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(170, 380, 91, 32));
        pushButton_cancel->setStyleSheet(QString::fromUtf8("background-color:rgb(184, 184, 184);\n"
"color:black;\n"
"border-style: outset;\n"
"border-radius: 10px;"));
        widget = new QWidget(saveLocation);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 421, 23));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_locationName = new QLineEdit(widget);
        lineEdit_locationName->setObjectName(QString::fromUtf8("lineEdit_locationName"));

        horizontalLayout->addWidget(lineEdit_locationName);


        retranslateUi(saveLocation);

        QMetaObject::connectSlotsByName(saveLocation);
    } // setupUi

    void retranslateUi(QDialog *saveLocation)
    {
        saveLocation->setWindowTitle(QCoreApplication::translate("saveLocation", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("saveLocation", "Click the map to create a Zone:", nullptr));
        pushButton_saveNewLocation->setText(QCoreApplication::translate("saveLocation", "Save New Location!", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("saveLocation", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("saveLocation", "Location Name:", nullptr));
        lineEdit_locationName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class saveLocation: public Ui_saveLocation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVELOCATION_H
