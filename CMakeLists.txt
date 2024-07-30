cmake_minimum_required(VERSION 3.16)

project(Client VERSION 0.1 LANGUAGES CXX)

configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config.h @ONLY)

set(icon_resource "${CMAKE_CURRENT_SOURCE_DIR}/res.rc")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME}
    main.cpp
    clientview.h
    clientview.cpp
    clientviewmodel.h
    clientviewmodel.cpp
    clientmodel.h
    clientmodel.cpp

    README.md
    config.h.in
    ${icon_resource}
)

qt_add_qml_module(${PROJECT_NAME}
    URI Client
    VERSION 1.0
    QML_FILES
        GUI/ButtonConnectToServer.qml
	GUI/ButtonSendMessage.qml
	GUI/ButtonTemplate.qml
	GUI/ClientWindow.qml
	GUI/InputMessage.qml
	GUI/InputText.qml
	GUI/InputTextMessages.qml
	GUI/InputTextName.qml
	GUI/InputTextPortClient.qml
	GUI/InputTextServerIP.qml
	GUI/ItemsForConnecting.qml
	GUI/LabelsText.qml
	GUI/LabelsTextForDelegate.qml
	GUI/LightConnected.qml
	GUI/ListViewClientMessages.qml

	GUI/ClientFuncs.js
	res.rc
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Quick
)

install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
