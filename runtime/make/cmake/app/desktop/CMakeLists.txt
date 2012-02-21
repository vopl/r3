PROJECT (desktop)

FIND_PACKAGE(Qt4 4.7.4 REQUIRED QtCore QtScript QtScriptTools QtGui)
INCLUDE(${QT_USE_FILE})

#MESSAGE("defs: ${QT_DEFINITIONS}")	
#MESSAGE("incs: ${QT_INCLUDES}")
#MESSAGE("libs: ${QT_LIBRARY_DIR}")

#INCLUDE_DIRECTORIES(${QT_INCLUDES})

SET(SRC
	${SRC_DIR}/desktop/entry.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_QT
	${SRC_DIR}/desktop/errorCode.cpp
	${SRC_DIR}/desktop/client.cpp
	${SRC_DIR}/desktop/session.cpp
	${SRC_DIR}/desktop/agent.cpp
	${SRC_DIR}/desktop/signal.cpp
)
SOURCE_GROUP(src FILES ${SRC_QT})


SET(SRC_NOPCH
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})


SET(SRC_HDR
	${SRC_DIR}/desktop/pch.hpp
)
SOURCE_GROUP(src FILES ${SRC_HDR})

SET(SRC_QT_HDR
	${SRC_DIR}/desktop/errorCode.hpp
	${SRC_DIR}/desktop/client.hpp
	${SRC_DIR}/desktop/session.hpp
	${SRC_DIR}/desktop/agent.hpp
	${SRC_DIR}/desktop/signal.hpp
)
SOURCE_GROUP(src FILES ${SRC_QT_HDR})
QT4_WRAP_CPP(MOC_SOURCES ${SRC_QT_HDR})
SOURCE_GROUP(genarated FILES ${MOC_SOURCES})

IF(MSVC)
	SET(SRC_PCH ${SRC_DIR}/desktop/pch.cpp)
	SOURCE_GROUP(src FILES ${SRC_PCH})
ENDIF()









SET(SRC_QT_RES
	${SRC_DIR}/desktop/res/index.qrc
)
SOURCE_GROUP(src\\res FILES ${SRC_QT_RES})
QT4_ADD_RESOURCES(SRC_QT_RES_GEN ${SRC_QT_RES})
SOURCE_GROUP(genarated FILES ${SRC_QT_RES_GEN})

IF(MSVC AND FALSE)
	SET(SRC_QT_RES_FILES
		${SRC_DIR}/desktop/res/main.js
		${SRC_DIR}/desktop/res/uiLoader.js
		${SRC_DIR}/desktop/res/network.js

		${SRC_DIR}/desktop/res/mainWindow.ui
		${SRC_DIR}/desktop/res/mainWindowIcon.png
		
		${SRC_DIR}/desktop/res/networkDialog.ui
	)
	SOURCE_GROUP(src\\res FILES ${SRC_QT_RES_FILES})
	SET_SOURCE_FILES_PROPERTIES(${SRC_QT_RES_FILES} PROPERTIES LANGUAGE "")
ENDIF()









ADD_EXECUTABLE(desktop 
	${SRC_PCH} 
	${SRC} ${SRC_NOPCH} ${SRC_HDR} 
	${SRC_QT} ${SRC_QT_HDR} ${MOC_SOURCES} 
	${SRC_QT_RES} ${SRC_QT_RES_GEN} ${SRC_QT_RES_FILES})
CREATE_PCH(desktop ${SRC_DIR}/desktop/pch.hpp ${SRC_PCH})
USE_PCH(desktop ${SRC_DIR}/desktop/pch.hpp ${SRC})
USE_PCH(desktop ${SRC_DIR}/desktop/pch.hpp ${SRC_QT})

SETUP_BIN_OUT(desktop client)

TARGET_LINK_LIBRARIES(desktop libheap libutils libpluma libasync liblog)

IF(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG)
	TARGET_LINK_LIBRARIES(desktop ${Boost_LIBRARIES})
ENDIF()

IF(UNIX)
	SET(CMAKE_THREAD_PREFER_PTHREAD ON)
	INCLUDE(FindThreads)
	TARGET_LINK_LIBRARIES(desktop ${CMAKE_THREAD_LIBS_INIT})
ENDIF()

TARGET_LINK_LIBRARIES(desktop ${QT_LIBRARIES})
