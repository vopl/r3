PROJECT(client)

FIND_PACKAGE(Qt4 4.7.4 REQUIRED QtCore QtGui)
INCLUDE(${QT_USE_FILE})






SET(SRC
	${SRC_DIR}/client/entry.cpp
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC})
QT4_AUTOMOC(${SRC})






#SET(qtproject_UIS
#    main_window.ui
#)

#QT4_WRAP_UI(qtproject_UIS_H ${qtproject_UIS})





INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

PRESETUP_BIN_OUT(SRC_STUB)
ADD_EXECUTABLE(client ${SRC_STUB} ${SRC})
SETUP_BIN_OUT(client client)

TARGET_LINK_LIBRARIES(client libheap libpluma)
TARGET_LINK_LIBRARIES(client ${QT_LIBRARIES})
