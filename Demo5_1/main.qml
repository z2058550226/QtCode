import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Dialogs 1.2

Window {
    visible: true
    width: 360
    height: 360

    Rectangle {
        id: rectangle3
        x: 22
        y: 65
        width: 317
        height: 230
        color: "#ffffff"
        radius: 1
        border.width: 1




        Rectangle {
            id: rectangle
            x: 92
            y: 18
            width: 205
            height: 52
            color: "#ffffff"
            radius: 5
            border.width: 1

            TextInput {
                id: et_username
                x: 13
                y: 16
                width: 184
                height: 20
                text: qsTr("")
                font.pixelSize: 12
            }
        }


        Rectangle {
            id: rectangle1
            x: 90
            y: 105
            width: 205
            height: 52
            color: "#ffffff"
            radius: 5
            border.width: 1

            TextInput {
                id: et_password
                x: 13
                y: 16
                width: 184
                height: 20
                text: qsTr("")
                echoMode: TextInput.Password
                font.pixelSize: 12
            }
        }

        MouseArea {
            id: mouseArea
            x: 60
            y: 180
            width: 180
            height: 30
            onClicked: {
                messageDialog.text="Username is " +
                        et_username.text + " and Password is "+
                        et_password.text
                messageDialog.visible = true
            }

            Rectangle {
                id: rectangle2
                color: "#cccccc"
                radius: 5
                border.width: 1
                anchors.fill: parent

                Text {
                    id: text3
                    text: qsTr("Login")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.fill: parent
                    font.pixelSize: 12
                }
            }
        }

        Text {
            id: text2
            x: 16
            y: 127
            text: qsTr("Password:")
            font.pixelSize: 12
        }

        Text {
            id: text1
            x: 16
            y: 41
            text: qsTr("Username:")
            font.pixelSize: 12
        }
    }

    MessageDialog{
        id:messageDialog
        title: "Fake Login"
        text: ""
        onAccepted: {
            console.log("You have click the Login function")
            Qt.quit()
        }
    }

}
