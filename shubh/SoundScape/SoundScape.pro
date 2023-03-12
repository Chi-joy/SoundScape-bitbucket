QT       += core gui
QT += network
QT += webengine webenginewidgets
QT += networkauth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    loginwindow.cpp \
    spotifyapi.cpp

HEADERS += \
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
    spotifyapi.h



FORMS += \
    loginwindow.ui

TRANSLATIONS += \
    SoundScape_en_CA.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../../../../Downloads/curl-5ab5018bf8f0e39957d264f33c3eeddd958ed5d8-include/curl/curlbuild.h.cmake \
    ../../../../../../Downloads/curl-5ab5018bf8f0e39957d264f33c3eeddd958ed5d8-include/curl/stamp-h3 \
    ../cs3307_gc/curl/Makefile.am \
    ../make_getPlaylists/curl/Makefile.am \
    curl/Makefile.am
