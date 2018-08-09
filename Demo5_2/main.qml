import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id:window
    visible: true
    width: 640
    height: 480
    property alias mouseArea: touchArea
    property alias image: machao
    title: qsTr("Hello World")

    property int prevPointX: 0
    property int prevPointY: 0
    property int curPointX: 0
    property int curPointY: 0

    property int prevDistX: 0
    property int prevDistY: 0
    property int curDistX: 0
    property int curDistY: 0

    property int tuxWidth: machao.width
    property int tuxHeight: machao.height

    MultiPointTouchArea {
        id: touchArea
        anchors.fill: parent
        touchPoints: [
            TouchPoint {
                id:point1
            },
            TouchPoint {
                id:point2
            }
        ]
        onPressed:{
            if(point2.pressed){
                if(point2.x<point1.x){
                    prevDistX = point2.x-point1.x
                }
                else{
                    prevDistX = point1.x-point2.x
                }

                if(point2.y<point1.y){
                    prevDistY = point2.y-point1.y
                }
                else{
                    prevDistY = point1.y-point2.y
                }
                tuxWidth = machao.width
                tuxHeight =machao.height
            }
        }

        onUpdated: {
            if(!point2.pressed){
                machao.x+=point1.x-point1.previousX
                machao.y+=point1.y-point1.previousY
            }else{
                if(point2.x<point1.x){
                    curDistX=point2.x-point1.x
                }else{
                    curDistX=point1.x-point2.x
                }

                if(point2.y<point1.y){
                    curDistY=point2.y-point1.y
                }else{
                    curDistY=point1.y-point2.y
                }

                machao.width = tuxWidth+prevDistX-curDistX
                machao.height = tuxHeight+prevDistY-curDistY
            }
        }
    }
    Image {
        id: machao
        x: (window.width/2)-(machao.width/2)
        y: (window.height/2)-(machao.height/2)
        width: 200
        height: 220
        fillMode: Image.PreserveAspectFit
        source: "test.jpg"
    }
}
