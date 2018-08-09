import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Window {
    id: window
    visible: true
    width: 480
    height: 550

    Button {
        id: button1
        y: 0
        height: 45
        text: qsTr("Button")
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        Behavior on y{
            SpringAnimation{
                spring:2;damping: 0.2
            }
        }
        onClicked: {
            y=y+(45*3);
        }
    }

    Button {
        id: button2
        y: 45
        height: 45
        text: qsTr("Button")
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        Behavior on y{
            SpringAnimation{
                spring:2;damping: 0.2
            }
        }
        onClicked: {
            y=y+(45*3);
        }
    }

    Button {
        id: button3
        y: 90
        height: 45
        text: qsTr("Button")
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        Behavior on y{
            SpringAnimation{
                spring:2;damping: 0.2
            }
        }
        onClicked: {
            y=y+(45*3);
        }
    }

    MouseArea {
        id: mouseArea
        x: 106
        y: 299
        width: 100
        height: 100
        SequentialAnimation on x{
            loops: Animation.Infinite
            PropertyAnimation{to:150;duration: 1500}
            PropertyAnimation{to:50;duration:500 }
        }
        onClicked: {
            if(rect2.state=="BLUE"){
                rect2.state="RED"
            }else{
                rect2.state="BLUE"
            }
        }

        Rectangle {
            id: rect2
            color: "#0000ff"
            anchors.fill: parent
            states:[
                State{
                    name:"BLUE"
                    PropertyChanges {
                        target: rect2
                        color:"blue"

                    }
                },
                State {
                    name: "RED"
                    PropertyChanges {
                        target: rect2
                        color:"red"

                    }
                }
            ]
        }
    }

    MouseArea {
        id: mouseArea1
        x: 379
        y: 308
        width: 100
        height: 100

        Image {
            id: hiiragi
            anchors.fill: parent
            source: "tongsi.png"
            RotationAnimation on rotation {
                id:anim01
                loops: Animation.Infinite
                from: 0
                to:-360
                duration: 1000
            }
        }

        onPressed: {
            if(anim01.paused){
                anim01.resume()
            }else{
                anim01.pause()
            }
        }
    }
}
