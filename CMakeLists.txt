cmake_minimum_required(VERSION 3.20)

project(Pianix
    VERSION 1.0.0
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia SerialPort)

add_executable(pianix
    main.cpp res.qrc
    device.cpp
    mainwindow.cpp
    notewidget.cpp
)

target_link_libraries(pianix PRIVATE Qt::Widgets Qt::Multimedia Qt::SerialPort)
