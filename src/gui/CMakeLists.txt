set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#set(RC_FILE "")

add_executable(ptflapp
  main.cpp
  mainwindow.cpp
  utils/noneditabletablewidgetitem.cpp
  widgets/accountswidget.cpp
  widgets/stockstablewidget.cpp
)

target_link_libraries(ptflapp Qt5::Widgets dbcomm)
target_include_directories(ptflapp PRIVATE ${CMAKE_SOURCE_DIR}/src/gui)
