/********************************************************************************
** Form generated from reading UI file 'createplaylistmap.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPLAYLISTMAP_H
#define UI_CREATEPLAYLISTMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_createPlaylistMap
{
public:

    void setupUi(QDialog *createPlaylistMap)
    {
        if (createPlaylistMap->objectName().isEmpty())
            createPlaylistMap->setObjectName(QString::fromUtf8("createPlaylistMap"));
        createPlaylistMap->resize(400, 300);

        retranslateUi(createPlaylistMap);

        QMetaObject::connectSlotsByName(createPlaylistMap);
    } // setupUi

    void retranslateUi(QDialog *createPlaylistMap)
    {
        createPlaylistMap->setWindowTitle(QCoreApplication::translate("createPlaylistMap", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createPlaylistMap: public Ui_createPlaylistMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPLAYLISTMAP_H
