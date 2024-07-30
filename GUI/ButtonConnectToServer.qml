import QtQuick
import "ClientFuncs.js" as Funcs

ButtonTemplate {
    id: button_connect_to_server

    LabelsText {
        id: button_server_text
        anchors.fill: parent
        text: connectedToServer ? "disconnect" : "connect"
    }

    states:
        [
        State {
            name: "disable"

            when: client_text_port.client_port_isAccepted == false
            || client_text_name.name_text == ""

            PropertyChanges {
                target: button_connect_to_server
                enabled: false
            }
            PropertyChanges {
                target: grad_start_pos_
                color: "#B4B2B3"
            }
            PropertyChanges {
                target: grad_stop_pos_
                color: "#696868"
            }
        }
    ]

    Component.onCompleted:
    {
        client_view.errorClient.connect(Funcs.setErrorFlag)
    }
}
