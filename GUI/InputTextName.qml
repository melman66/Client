import QtQuick
import "ClientFuncs.js" as Funcs

Rectangle{
    id: client_name_rect
    color: connectedToServer ? "#B9A583" : "#ffe4b5"
    radius: 5

    property alias name_text: client_input_text_name.text

    InputText{
        id: client_input_text_name
        width: parent.width
        height: parent.height
        enabled: connectedToServer ? false : true
        color: connectedToServer ? "#716551" : "#2e1300"
        validator: RegularExpressionValidator {
            regularExpression: /[A-Z, a-z, А-Я, а-я]+/
        }
    }
    Component.onCompleted: {
        client_view.newClientName.connect(Funcs.setNewClientName);
    }
}
