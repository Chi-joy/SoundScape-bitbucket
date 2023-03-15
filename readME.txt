(*due to issues with wsl testing, spotify login functionality is not working and map
*interactions are iffy as well. if attempting spotify login, use 
username: 06quiver-saying@icloud.com
pass: Password3465)

This is a qmake project and requires qmake to be installed on the system this can be
done by running $ sudo apt-get install qt5-qmake
additionally we require the following qt modules to be installed




libqt5concurrent5:amd64
libqt5core5a:amd64
libqt5dbus5:amd64
libqt5designer5:amd64
libqt5designercomponents5:amd64
libqt5gui5:amd64
libqt5help5:amd64
libqt5location5:amd64
libqt5location5-plugin-mapboxgl:amd64
libqt5location5-plugins:amd64
libqt5network5:amd64
libqt5networkauth5:amd64
libqt5networkauth5-dev:amd64
libqt5opengl5:amd64
libqt5opengl5-dev:amd64
libqt5positioning5:amd64
libqt5positioning5-plugins:amd64
libqt5positioningquick5:amd64
libqt5printsupport5:amd64
libqt5qml5:amd64
libqt5qmlmodels5:amd64
libqt5qmlworkerscript5:amd64
libqt5quick5:amd64
libqt5quickparticles5:amd64
libqt5quickshapes5:amd64
libqt5quicktest5:amd64
libqt5quickwidgets5:amd64
libqt5sensors5:amd64
libqt5sql5:amd64
libqt5sql5-sqlite:amd64
libqt5svg5:amd64
libqt5svg5-dev:amd64
libqt5test5:amd64
libqt5webchannel5:amd64
libqt5webchannel5-dev:amd64
libqt5webengine-data
libqt5webengine5:amd64
libqt5webenginecore5:amd64
libqt5webenginewidgets5:amd64
libqt5webkit5:amd64
libqt5widgets5:amd64
libqt5xml5:amd64
qdoc-qt5
qhelpgenerator-qt5
qt5-assistant
qt5-gtk-platformtheme:amd64
qt5-qmake:amd64
qt5-qmake-bin
qt5-qmltooling-plugins:amd64
qtattributionsscanner-qt5
qml-module-qtlocation 
qml-module-qtpositioning


to build the project, perform the folling commands from the project directory
mkdir build
cd build
qmake ./SoundScape.pro
make


then to run it run:
./SoundScape

use "test" for username and password