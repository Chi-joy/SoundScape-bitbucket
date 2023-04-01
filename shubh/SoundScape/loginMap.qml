import QtQuick 2.15

import QtPositioning 5.6
import QtLocation 5.6


//not being used
Item {
    property double oldLat: 43.009953
    property double oldLng: -81.273613
    PositionSource {
        active: true
        onPositionChanged: {
            console.log(position.coordinate);
        }
    }

    Plugin {
        id: mapPlugin
        name: "osm"

    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        //center: QtPositioning.coordinate(43.009953,-81.273613)


        center: QtPositioning.coordinate(centerCoordinate.latitude, centerCoordinate.longitude)
        zoomLevel: 15


        function setCenter(lat,lng) {
            //map.pan(oldLat - lat, oldLng - lng)

            map.toCoordinate(Qt.point(lat,lng));
            oldLat = lat
            oldLng = lng
        }

        MapQuickItem {
            id:marker
            sourceItem: Image{
                id: image
                source: "marker.png"

            }
            coordinate: map.center
            anchorPoint.x: image.width / 2
            anchorPoint.y: image.height / 2


        }

//    MouseArea {
//        anchors.fill: parent
//        onPressed: {
//            marker.coordinate = map.toCoordinate(Qt.point(mouse.x,mouse.y))
//        }
//    }

    }
}
