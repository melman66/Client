import QtQuick

Rectangle {
    id: client_text_ip_rect
    color: connectedToServer ? "#B9A583" : "#ffe4b5"
    radius: 5

    property alias client_string_ip: input_text_server_ip.text

    InputText{
        id: input_text_server_ip
        width: parent.width
        height: parent.height
        enabled: connectedToServer ? false : true
        color: connectedToServer ? "#716551" : "#2e1300"
        inputMask: "000.000.000.000"
        text: "192.168.1.177"
    }
}
