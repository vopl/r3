PROJECT(client)

FIND_PACKAGE(Qt4 4.7.4 REQUIRED QtCore QtGui)
INCLUDE(${QT_USE_FILE})




SET(SRC_NOPCH
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})


SET(SRC
	${SRC_DIR}/client/entry.cpp
)
SOURCE_GROUP(src FILES ${SRC})
QT4_AUTOMOC(${SRC})

SET(SRC_HDR
	${SRC_DIR}/client/pchqt.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})








SET(SRC_QT
	${SRC_DIR}/client/qt/mainWindow.cpp
	${SRC_DIR}/client/qt/networkDialog.cpp
)
SOURCE_GROUP(src\\qt FILES ${SRC_QT})
#wtf? QT4_AUTOMOC(${SRC_QT})

SET(SRC_QT_HDR
	${SRC_DIR}/client/qt/mainWindow.hpp
	${SRC_DIR}/client/qt/networkDialog.hpp
)
SOURCE_GROUP(src\\qt FILES ${SRC_QT_HDR})
QT4_WRAP_CPP(MOC_SOURCES ${SRC_QT_HDR})
SOURCE_GROUP(genarated FILES ${MOC_SOURCES})

SET(SRC_QT_UI
	${SRC_DIR}/client/qt/mainWindow.ui
	${SRC_DIR}/client/qt/networkDialog.ui
)
SOURCE_GROUP(src\\qt FILES ${SRC_QT_UI})
QT4_WRAP_UI(UI_HEADERS ${SRC_QT_UI})
SOURCE_GROUP(genarated FILES ${UI_HEADERS})







SET(SRC_PCH
	${SRC_DIR}/client/pchqt.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})



INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

PRESETUP_BIN_OUT(SRC_STUB)
ADD_EXECUTABLE(client
	${SRC_STUB} ${SRC_NOPCH} ${SRC_PCH} ${SRC} ${SRC_HDR} 
	${SRC_QT} ${SRC_QT_HDR} ${MOC_SOURCES} ${UI_HEADERS})

CREATE_PCH(client ${SRC_DIR}/client/pchqt.h ${SRC_PCH})
USE_PCH(client ${SRC_DIR}/client/pchqt.h ${SRC})
USE_PCH(client ${SRC_QT_DIR}/client/pchqt.h ${SRC_QT})
SETUP_BIN_OUT(client client)

TARGET_LINK_LIBRARIES(client libheap libpluma)
TARGET_LINK_LIBRARIES(client ${QT_LIBRARIES})

#IF(WIN32)
#	TARGET_LINK_LIBRARIES(client ${QT_QTMAIN_LIBRARY})
#ENDIF(WIN32)