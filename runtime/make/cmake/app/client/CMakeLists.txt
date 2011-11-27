PROJECT(client)

FIND_PACKAGE(Qt4 4.7.4 REQUIRED QtCore QtGui)
INCLUDE(${QT_USE_FILE})






SET(SRC
	${SRC_DIR}/client/entry.cpp
)
SOURCE_GROUP(src FILES ${SRC})
QT4_AUTOMOC(${SRC})

SET(SRC_NOPCH
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})


SET(SRC_HDR
	${SRC_DIR}/client/pchqt.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})



#SET(qtproject_UIS
#    main_window.ui
#)

#QT4_WRAP_UI(qtproject_UIS_H ${qtproject_UIS})


SET(SRC_PCH
	${SRC_DIR}/client/pchqt.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})



INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

PRESETUP_BIN_OUT(SRC_STUB)
ADD_EXECUTABLE(client ${SRC_STUB} ${SRC} ${SRC_NOPCH} ${SRC_PCH} ${SRC_HDR})
CREATE_PCH(client ${SRC_DIR}/client/pchqt.h ${SRC_PCH})
USE_PCH(client ${SRC_DIR}/client/pchqt.h ${SRC})
SETUP_BIN_OUT(client client)

TARGET_LINK_LIBRARIES(client libheap libpluma)
TARGET_LINK_LIBRARIES(client ${QT_LIBRARIES})
