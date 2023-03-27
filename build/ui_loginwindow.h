/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_login;
    QGraphicsView *graphicsView;
    QLineEdit *lineEdit_username;
    QLabel *loginTitle;
    QPushButton *pushButton_login;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_password;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_playlists;
    QListView *listView_playlists;
    QGroupBox *groupBox_pushButtons;
    QPushButton *pushButton_playlists;
    QPushButton *pushButton_coor;
    QPushButton *pushButton_spotify;
    QQuickWidget *quickWidget_map;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(809, 412);
        LoginWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox_login = new QGroupBox(centralwidget);
        groupBox_login->setObjectName(QStringLiteral("groupBox_login"));
        groupBox_login->setEnabled(true);
        groupBox_login->setGeometry(QRect(270, 50, 321, 231));
        graphicsView = new QGraphicsView(groupBox_login);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 20, 321, 211));
        graphicsView->setAutoFillBackground(false);
        graphicsView->setStyleSheet(QLatin1String("background: qradialgradient(cx:0.5, cy:0.5, radius:1.5, fx:0.499586, fy:0.5, stop:0 rgba(31, 217, 96, 255), stop:1 rgba(255, 255, 255, 255))\n"
""));
        QBrush brush(QColor(148, 33, 146, 255));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);
        QBrush brush1(QColor(255, 147, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        graphicsView->setForegroundBrush(brush1);
        lineEdit_username = new QLineEdit(groupBox_login);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(131, 107, 125, 21));
        lineEdit_username->setStyleSheet(QStringLiteral(""));
        loginTitle = new QLabel(groupBox_login);
        loginTitle->setObjectName(QStringLiteral("loginTitle"));
        loginTitle->setGeometry(QRect(60, 60, 189, 29));
        loginTitle->setStyleSheet(QStringLiteral("color:white;"));
        loginTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_login = new QPushButton(groupBox_login);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));
        pushButton_login->setGeometry(QRect(60, 180, 201, 20));
        pushButton_login->setStyleSheet(QLatin1String("background-color:white;\n"
"color:green;\n"
"border-style: outset;\n"
"border-radius: 10px;\n"
"border-width: 2px;\n"
"border-color: white;\n"
"font: QFont f(\"Helvetica\");"));
        label_3 = new QLabel(groupBox_login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 140, 62, 16));
        label_3->setStyleSheet(QStringLiteral("color:white;"));
        label_4 = new QLabel(groupBox_login);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(58, 106, 65, 16));
        label_4->setStyleSheet(QStringLiteral("color:white;"));
        lineEdit_password = new QLineEdit(groupBox_login);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(131, 138, 125, 21));
        lineEdit_password->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox_playlists = new QGroupBox(centralwidget);
        groupBox_playlists->setObjectName(QStringLiteral("groupBox_playlists"));
        groupBox_playlists->setGeometry(QRect(10, 10, 169, 361));
        listView_playlists = new QListView(groupBox_playlists);
        listView_playlists->setObjectName(QStringLiteral("listView_playlists"));
        listView_playlists->setGeometry(QRect(1, 20, 171, 351));
        listView_playlists->setStyleSheet(QLatin1String("background: white;\n"
"color: black;"));
        groupBox_pushButtons = new QGroupBox(centralwidget);
        groupBox_pushButtons->setObjectName(QStringLiteral("groupBox_pushButtons"));
        groupBox_pushButtons->setGeometry(QRect(620, 0, 181, 161));
        pushButton_playlists = new QPushButton(groupBox_pushButtons);
        pushButton_playlists->setObjectName(QStringLiteral("pushButton_playlists"));
        pushButton_playlists->setGeometry(QRect(20, 22, 147, 32));
        pushButton_playlists->setStyleSheet(QLatin1String("background-color:rgb(30,215,96);\n"
"color:black;\n"
"border-style: outset;\n"
"border-radius: 10px;\n"
""));
        pushButton_coor = new QPushButton(groupBox_pushButtons);
        pushButton_coor->setObjectName(QStringLiteral("pushButton_coor"));
        pushButton_coor->setGeometry(QRect(20, 56, 147, 32));
        pushButton_coor->setStyleSheet(QLatin1String("background-color:rgb(30,215,96);\n"
"color:black;\n"
"border-style: outset;\n"
"border-radius: 10px;"));
        pushButton_spotify = new QPushButton(groupBox_pushButtons);
        pushButton_spotify->setObjectName(QStringLiteral("pushButton_spotify"));
        pushButton_spotify->setGeometry(QRect(20, 90, 147, 32));
        pushButton_spotify->setStyleSheet(QLatin1String("background-color:rgb(30,215,96);\n"
"color:black;\n"
"border-style: outset;\n"
"border-radius: 10px;"));
        quickWidget_map = new QQuickWidget(centralwidget);
        quickWidget_map->setObjectName(QStringLiteral("quickWidget_map"));
        quickWidget_map->setGeometry(QRect(190, 30, 431, 341));
        quickWidget_map->setResizeMode(QQuickWidget::SizeRootObjectToView);
        LoginWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "LoginWindow", Q_NULLPTR));
        groupBox_login->setTitle(QApplication::translate("LoginWindow", "Login", Q_NULLPTR));
        loginTitle->setText(QApplication::translate("LoginWindow", "<html>\n"
"  <head>\n"
"    <style>\n"
"      body {\n"
"        font-family: Arial, sans-serif;\n"
"        background-color: #f2f2f2;\n"
"      }\n"
"  p {\n"
"    color: #f8f8ff;\n"
"    font-size: 16px;\n"
"    line-height: 1.5;\n"
"  }\n"
"</style>\n"
"  </head>\n"
"  <body>\n"
"    <p>Welcome to SoundScape!</p>\n"
"  </body>\n"
"</html>\n"
"\n"
"\n"
"\n"
"\n"
"", Q_NULLPTR));
        pushButton_login->setText(QApplication::translate("LoginWindow", "Login!", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoginWindow", "Password:", Q_NULLPTR));
        label_4->setText(QApplication::translate("LoginWindow", "Username:", Q_NULLPTR));
        groupBox_playlists->setTitle(QApplication::translate("LoginWindow", "My playlists:", Q_NULLPTR));
        groupBox_pushButtons->setTitle(QString());
        pushButton_playlists->setText(QApplication::translate("LoginWindow", "Get my playlists", Q_NULLPTR));
        pushButton_coor->setText(QApplication::translate("LoginWindow", "Get my coordinates", Q_NULLPTR));
        pushButton_spotify->setText(QApplication::translate("LoginWindow", "Connect to Spotify", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
