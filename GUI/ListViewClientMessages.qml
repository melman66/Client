import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts
import Client
import "ClientFuncs.js" as Funcs

Rectangle{
    id: list_view_client_messages_main_rect
    color: "#FED7A8"
    radius: 10

    ListModel{
        id: clients_messages_list_model
        ListElement{
            message: "Welcome to Client!"
        }
    }

    Component {
        id: delegate_list_view_messages

        Item {
            id: delegate_item
            width: delegate_text_messages.width + 5
            height: delegate_text_messages.height + 5

            LabelsTextForDelegate{
                id: delegate_text_messages
                delegate_text.text: modelData
            }
        }
    }

    ListView{
        id: list_view_client_messages
        model:clients_messages_list_model
        delegate: delegate_list_view_messages
        width: parent.width
        height: parent.height - 5
        clip: true
        ScrollBar.vertical: ScrollBar{ id: scroll_messages }
        onCountChanged: { scroll_messages.position = contentHeight }
    }

    Component.onCompleted: {
        client_view.messageSended.connect(Funcs.addMessageToList)
        client_view.sendMsgToGUI.connect(Funcs.addMessageToList)
        client_view.errorClient.connect(Funcs.addMessageToList)
    }
}
