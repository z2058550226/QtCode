import QtQuick 2.9
import QtQuick.Window 2.2
import MyClassLib 1.0

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MyClass{
        id:myClass
    }

    MouseArea {
        id: mouseArea
        x: 526
        y: 13
        width: 100
        height: 100
    }

    Text {
        id: messageText
        x: 213
        y: 397
        width: 300
        height: 20
        text: qsTr("Change this text using c++")
        anchors.verticalCenterOffset: 120
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 18
    }

    Rectangle {
        id: square
        x: 226
        y: 93
        width: 200
        height: 200
        color: "#ff0d0d"
        anchors.verticalCenterOffset: -14
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    Component.onCompleted: {
        myClass.setMyObject(messageText)
    }
}
