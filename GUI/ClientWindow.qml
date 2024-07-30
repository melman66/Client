import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Window
import QtQuick.Layouts
import Client
import "ClientFuncs.js" as ClientFuncs

Window {
    id: client_window

    property bool connectedToServer: client_view.connectedState
    property bool error_flag: false

    ClientView{
        id: client_view
    }

    minimumHeight: 400
    minimumWidth: 600
    maximumHeight: 400
    maximumWidth: 600
    x: 700
    y: 100
    visible: true
    title: "Client"

    Rectangle {
        color: "#febc6b"
        anchors.fill: parent

        GridLayout{
            anchors.fill: parent
            columns: 2
            columnSpacing: 10
            rowSpacing: 10

            ListViewClientMessages{
                id: list_view_client_messages
                Layout.topMargin: 10
                Layout.leftMargin: 10
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            ItemsForConnecting{
                id: items_for_connecting
                Layout.alignment: Qt.AlignTop
                Layout.topMargin: 10
                Layout.rightMargin: 10
                Layout.preferredWidth: 160
                Layout.preferredHeight: 300
            }

            InputMessage {
                id: client_input_message
                Layout.bottomMargin: 10
                Layout.leftMargin: 10
                Layout.fillWidth: true
                Layout.fillHeight: true
                input_message_rect.color: connectedToServer ? "#ffe4b5" : "#B9A583"
                enabled: connectedToServer ? 1 : 0
                input_message_text.placeholderText:
                    connectedToServer ? "Enter text..." : ""
            }

            ButtonSendMessage {
                id: button_send_message
                Layout.bottomMargin: 10
                Layout.rightMargin: 10
                Layout.preferredWidth: items_for_connecting.width
                Layout.preferredHeight: 70
                enabled: (connectedToServer
                          && (client_input_message.input_message_text.text !== ""))
                         ? 1 : 0
                grad_start_pos.color: (connectedToServer
                                       && (client_input_message.input_message_text.text !== ""))
                                      ? "#FFD8B5" : "#B4B2B3"
                grad_stop_pos.color:  (connectedToServer
                                       && (client_input_message.input_message_text.text !== ""))
                                      ? "#e16b44" : "#696868"
                onClicked: ClientFuncs.sendMessageToServer(
                               client_input_message.input_message_text.text)
            }
        }
    }
    Component.onCompleted: {
        client_view.connectedStateChanged.connect(ClientFuncs.changeConnectedToServerState)
    }
}
