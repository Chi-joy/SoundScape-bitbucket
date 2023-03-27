QT       += core gui
QT += network
QT += webengine webenginewidgets
QT += networkauth
QT += positioning # Add this line
QT += location

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets

CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++11
CONFIG += console
QML_IMPORT_PATH += /usr/lib/x86_64-linux-gnu/qt5/qml/QtLocation

LIBS += -lcurl
LIBS += -L/usr/lib/x86_64-linux-gnu \
        -lQt5Positioning

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GoogleAPI.cpp \
    HandlePlaylistMap.cpp \
    Location.cpp \
    PlaylistMap.cpp \
    Song.cpp \
    googleDelegate.cpp \
    main.cpp \
    loginwindow.cpp \
    playlist.cpp \
    request.cpp \
    selectplaylist.cpp \
    spotifyapi.cpp

HEADERS += \
    GoogleAPI.h \
    Location.h \
    PlaylistMap.h \
    Song.h \
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
    loginwindow.h \
    playlist.h \
    request.h \
    selectplaylist.h \
    spotifyapi.h



FORMS += \
    loginwindow.ui \
    selectLocationZone.ui \
    selectplaylist.ui

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
    curl/Makefile.am

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    main.qml
    marker.png

