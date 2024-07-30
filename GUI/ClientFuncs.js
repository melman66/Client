function addMessageToList(msg)
{
    clients_messages_list_model.append({"message" : msg})
}

function changeConnectedToServerState(state)
{
    connectedToServer = state
}

function connectToServer()
{
    if(error_flag == true) {
        error_flag = false
        return
    }

    if(button_connect_to_server.checked === true) {
        client_view.connectingToServer(client_text_server_ip.client_string_ip
                                       , client_text_port.client_string_port
                                       , client_text_name.name_text)
    }
    else {
        client_view.disconnectingFromServer();
    }
}

function sendMessageToServer(msg)
{
    if(connectedToServer) {
        if(client_view.sendMessageToServer(msg)){
            client_input_message.input_message_text.text = ""
            client_view.messageSended(client_view.getCurrentDateTime() + "\n"
                                      + "me:\n"
                                      + msg)
        }
    }
}

function setErrorFlag(err)
{
    connectedToServer = false
    error_flag = true
    button_connect_to_server.checked = false
}

function setNewClientName(name)
{
    name_text = name;
}
