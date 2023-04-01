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


    function setCenter(lat,lng) {
        //map.pan(oldLat - lat, oldLng - lng)

        map.toCoordinate(Qt.point(lat,lng));
        oldLat = lat
        oldLng = lng
    }

    MapQuickItem {

        //find out how to change marker size
        id:marker
        visible: false
        sourceItem: Image{
            id: image
            source: "marker.png"

        }
        coordinate: map.center

        //change to the end point of marker
        anchorPoint.x: 139
        anchorPoint.y: 137
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
