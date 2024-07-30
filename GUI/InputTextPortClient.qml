import QtQuick

Rectangle{
    id: client_text_port_rect
    color: connectedToServer ? "#B9A583" : "#ffe4b5"
    radius: 5

    property alias client_string_port: client_text_port.text
    property alias client_port_isAccepted: client_text_port.acceptableInput

    InputText{
        id: client_text_port
        width: parent.width
        height: parent.height
        text: "49152"
        enabled: connectedToServer ? false : true
        color: connectedToServer ? "#716551" : "#2e1300"
             && acceptableInput  ? "#2e1300" : "#ff1300"
        validator: IntValidator {
            top: 65535
            bottom: 49152
        }
    }
}
