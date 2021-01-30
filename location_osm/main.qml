import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.6
import QtPositioning 5.6


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Location ")

    Map{
        id: map;
        anchors.fill: parent;
        plugin: Plugin{name: "osm" }
        center: QtPositioning.coordinate(34.033333,-5.000000)
        zoomLevel: 15

        MapQuickItem{
            coordinate: QtPositioning.coordinate(34.033333,-5.000000)
            sourceItem: Image {
                id: picker
                source: "file:map-location.png"
            }
            anchorPoint.x: picker.width/2
            anchorPoint.y: picker.height

            }
        }
    }

