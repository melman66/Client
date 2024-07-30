import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts
import "ClientFuncs.js" as Funcs

Item{

    property alias alias_button_connect_to_server: button_connect_to_server

    ColumnLayout{
        anchors.fill: parent

        LightConnected{
            id: client_light_connected
            lightIsConnected: connectedToServer ? 1 : 0
        }
        Item{ height: 20 }

        LabelsText {
            Layout.fillWidth: true
            text: "Server IP"
        }
        InputTextServerIP{
            id: client_text_server_ip
            Layout.fillWidth: true
            height: client_light_connected.height
        }

        LabelsText {
            Layout.fillWidth: true
            text: "Port"
        }
        InputTextPortClient{
            id: client_text_port
            Layout.fillWidth: true
            height: client_text_server_ip.height
        }

        LabelsText {
            Layout.fillWidth: true
            text: "Name"
        }
        InputTextName{
            id: client_text_name
            Layout.fillWidth: true
            height: client_text_server_ip.height
        }

        Item{ Layout.fillHeight: true }

        ButtonConnectToServer{
            id: button_connect_to_server
            Layout.fillWidth: true
            onCheckedChanged: Funcs.connectToServer()
        }
    }
}
