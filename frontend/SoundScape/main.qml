import QtQuick 2.15
import QtPositioning 5.6
import QtLocation 5.6

//import PlaylistMapClass 1.0

//PlaylistMap {
//    id: playlistMap
//}


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

        center: QtPositioning.coordinate(43.009953,-81.273613)
        zoomLevel: 12
//        property variant centerCoordinate: QtPositioning.coordinate(43.009953,-81.273613)

//        center: QtPositioning.coordinate(centerCoordinate.latitude, centerCoordinate.longitude)

//        MapQuickItem {
//            id: mapItem
//            anchorPoint: Qt.point(10, 10)
//            coordinate: QtPositioning.coordinate(centerCoordinate.latitude, centerCoordinate.longitude)
//            sourceItem: Rectangle {
//                color: "red"
//                width: 10
//                height: 10
//            }
//        }

//        Component.onCompleted: {
//            map.activeMapItem = mapItem;
//            var camera = map.camera()
//            camera.setZoomLevel(12)
//            camera.setTarget(QtPositioning.coordinate(centerCoordinate.latitude, centerCoordinate.longitude))
//            map.setCamera(camera)
//        }

        MapQuickItem {

            //find out how to change marker size
            id:marker
            visible: false
            sourceItem: Image{
                id: image
                source: "marker-noshadow.png"

            }
            coordinate: map.center

            //change to the end point of marker
            anchorPoint.x: 130
            anchorPoint.y: 113
        }

        MouseArea {
            anchors.fill: parent
            propagateComposedEvents: true
            onPressed: {
                marker.visible = true
                marker.coordinate = map.toCoordinate(Qt.point(mouse.x,mouse.y))
            }


        }
    }


}
