QT       += core gui
QT += network
QT += webengine webenginewidgets
QT += networkauth
QT += location

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets

CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++11
CONFIG += console


LIBS += -lcurl

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GoogleAPI.cpp \
    Location.cpp \
    MetaData.cpp \
    PlaylistMap.cpp \
    Song.cpp \
    createplaylistmap.cpp \
    googleDelegate.cpp \
    locationjson.cpp \
    main.cpp \
    loginwindow.cpp \
    playlist.cpp \
    request.cpp \
    savelocation.cpp \
    selectplaylistwidget.cpp \
    spotifyapi.cpp

HEADERS += \
    GoogleAPI.h \
    Location.h \
    MetaData.h \
    PlaylistMap.h \
    Song.h \
    createplaylistmap.h \
    curl/curl.h \
    curl/curlver.h \
    curl/easy.h \
    curl/header.h \
    curl/mprintf.h \
    curl/multi.h \
    curl/options.h \
    curl/stdcheaders.h \
    curl/system.h \
    curl/typecheck-gcc.h \
    curl/urlapi.h \
    curl/websockets.h \
    json.hpp \
    locationjson.h \
    loginwindow.h \
    playlist.h \
    request.h \
    savelocation.h \
    selectplaylistwidget.h \
    spotifyapi.h



FORMS += \
    createplaylistmap.ui \
    loginwindow.ui \
    savelocation.ui \
    selectplaylistwidget.ui

TRANSLATIONS += \
    SoundScape_en_CA.ts
CONFIG += lrelease
CONFIG += embed_translations
CONFIG += sdk_no_version_check

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    curl/Makefile.am \
    locations.csv \
    loginMap.qml \
    main.qml \
    marker-noshadow.png \
    marker.png \
    mdata.csv \
    newLoc.qml

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    marker.png

