import QtQuick 2.15
import QtPositioning 5.6
import QtLocation 5.6

Item {
    PositionSource {
        active: true
        onPositionChanged: {
            console.log(position.coordinate);
        }
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: Plugin { name: "osm" }
        center: QtPositioning.coordinate(43.009953,-81.273613)
        zoomLevel: 15
    }


}
