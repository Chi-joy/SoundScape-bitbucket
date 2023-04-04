/********************************************************************************
** Form generated from reading UI file 'selectplaylistwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTPLAYLISTWIDGET_H
#define UI_SELECTPLAYLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectPlaylistWidget
{
public:
    QListView *listView_locations;
    QLabel *label;
    QPushButton *pushButton_cancel;
    QLabel *label_2;
    QListView *listView_playlists;
    QPushButton *pushButton_addLocation;
    QPushButton *pushButton_savePlaylistMap;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *selectPlaylistWidget)
    {
        if (selectPlaylistWidget->objectName().isEmpty())
            selectPlaylistWidget->setObjectName(QString::fromUtf8("selectPlaylistWidget"));
        selectPlaylistWidget->resize(431, 351);
        selectPlaylistWidget->setStyleSheet(QString::fromUtf8(""));
        listView_locations = new QListView(selectPlaylistWidget);
        listView_locations->setObjectName(QString::fromUtf8("listView_locations"));
        listView_locations->setGeometry(QRect(20, 40, 191, 251));
        listView_locations->setStyleSheet(QString::fromUtf8("background: white;\n"
"color: black;"));
        label = new QLabel(selectPlaylistWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 20, 231, 16));
        pushButton_cancel = new QPushButton(selectPlaylistWidget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(20, 300, 91, 32));
        pushButton_cancel->setStyleSheet(QString::fromUtf8("background-color:rgb(184, 184, 184);\n"
"color:black;\n"
"border-style: outset;\n"
"border-radius: 10px;"));
        label_2 = new QLabel(selectPlaylistWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 191, 16));
        listView_playlists = new QListView(selectPlaylistWidget);
        listView_playlists->setObjectName(QString::fromUtf8("listView_playlists"));
        listView_playlists->setGeometry(QRect(220, 40, 191, 251));
        listView_playlists->setStyleSheet(QString::fromUtf8("background: white;\n"
"color: black;"));
        pushButton_addLocation = new QPushButton(selectPlaylistWidget);
        pushButton_addLocation->setObjectName(QString::fromUtf8("pushButton_addLocation"));
        pushButton_addLocation->setGeometry(QRect(120, 300, 111, 32));
        pushButton_addLocation->setStyleSheet(QString::fromUtf8("background-color:rgb(184, 184, 184);\n"
"color:black;\n"
"border-style: outset;\n"
"border-radius: 10px;"));
        pushButton_savePlaylistMap = new QPushButton(selectPlaylistWidget);
        pushButton_savePlaylistMap->setObjectName(QString::fromUtf8("pushButton_savePlaylistMap"));
        pushButton_savePlaylistMap->setGeometry(QRect(240, 300, 171, 32));
        pushButton_savePlaylistMap->setStyleSheet(QString::fromUtf8("background-color:rgb(30,215,96);\n"
"color:black;\n"
"border-style: outset;\n"
"border-radius: 10px;"));
        graphicsView = new QGraphicsView(selectPlaylistWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 431, 351));
        graphicsView->raise();
        listView_locations->raise();
        label->raise();
        pushButton_cancel->raise();
        label_2->raise();
        listView_playlists->raise();
        pushButton_addLocation->raise();
        pushButton_savePlaylistMap->raise();

        retranslateUi(selectPlaylistWidget);

        QMetaObject::connectSlotsByName(selectPlaylistWidget);
    } // setupUi

    void retranslateUi(QWidget *selectPlaylistWidget)
    {
        selectPlaylistWidget->setWindowTitle(QCoreApplication::translate("selectPlaylistWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("selectPlaylistWidget", "Select a Playlist:", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("selectPlaylistWidget", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("selectPlaylistWidget", "Select a Location:", nullptr));
        pushButton_addLocation->setText(QCoreApplication::translate("selectPlaylistWidget", "Add a Location", nullptr));
        pushButton_savePlaylistMap->setText(QCoreApplication::translate("selectPlaylistWidget", "Create Playlist Map!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class selectPlaylistWidget: public Ui_selectPlaylistWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPLAYLISTWIDGET_H
