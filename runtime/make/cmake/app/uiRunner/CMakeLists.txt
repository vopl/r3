PROJECT (uiRunner)

FIND_PACKAGE(Qt4 4.7.4 REQUIRED QtCore QtScript QtScriptTools QtGui)
INCLUDE(${QT_USE_FILE})

#MESSAGE("defs: ${QT_DEFINITIONS}")	
#MESSAGE("incs: ${QT_INCLUDES}")
#MESSAGE("libs: ${QT_LIBRARY_DIR}")

#INCLUDE_DIRECTORIES(${QT_INCLUDES})

SET(SRC
	${SRC_DIR}/uiRunner/entry.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_QT
	${SRC_DIR}/uiRunner/fileEngineHandler.cpp
	${SRC_DIR}/uiRunner/errorCode.cpp
	${SRC_DIR}/uiRunner/client.cpp
	${SRC_DIR}/uiRunner/session.cpp
	${SRC_DIR}/uiRunner/agent.cpp
	${SRC_DIR}/uiRunner/signal.cpp
)
SOURCE_GROUP(src FILES ${SRC_QT})


SET(SRC_NOPCH
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})


SET(SRC_HDR
	${SRC_DIR}/uiRunner/pch.hpp
)
SOURCE_GROUP(src FILES ${SRC_HDR})

SET(SRC_QT_HDR
	${SRC_DIR}/uiRunner/errorCode.hpp
	${SRC_DIR}/uiRunner/client.hpp
	${SRC_DIR}/uiRunner/session.hpp
	${SRC_DIR}/uiRunner/agent.hpp
	${SRC_DIR}/uiRunner/signal.hpp
)
SOURCE_GROUP(src FILES ${SRC_QT_HDR})
QT4_WRAP_CPP(MOC_SOURCES ${SRC_QT_HDR})
SOURCE_GROUP(genarated FILES ${MOC_SOURCES})

SET(SRC_QT_HDR_NOMOC
	${SRC_DIR}/uiRunner/fileEngineHandler.hpp
)
SOURCE_GROUP(src FILES ${SRC_QT_HDR_NOMOC})

IF(MSVC)
	SET(SRC_PCH ${SRC_DIR}/uiRunner/pch.cpp)
	SOURCE_GROUP(src FILES ${SRC_PCH})
ENDIF()









SET(SRC_QT_RES
	${SRC_DIR}/uiRunner/res/index.qrc
)
SOURCE_GROUP(src\\res FILES ${SRC_QT_RES})
QT4_ADD_RESOURCES(SRC_QT_RES_GEN ${SRC_QT_RES})
SOURCE_GROUP(genarated FILES ${SRC_QT_RES_GEN})

IF(MSVC AND FALSE)
	SET(SRC_QT_RES_FILES
		${SRC_DIR}/uiRunner/res/main.js
		${SRC_DIR}/uiRunner/res/uiLoader.js
		${SRC_DIR}/uiRunner/res/network.js

		${SRC_DIR}/uiRunner/res/mainWindow.ui
		${SRC_DIR}/uiRunner/res/mainWindowIcon.png
		
		${SRC_DIR}/uiRunner/res/networkDialog.ui
	)
	SOURCE_GROUP(src\\res FILES ${SRC_QT_RES_FILES})
	SET_SOURCE_FILES_PROPERTIES(${SRC_QT_RES_FILES} PROPERTIES LANGUAGE "")
ENDIF()









ADD_EXECUTABLE(uiRunner 
	${SRC_PCH} 
	${SRC} ${SRC_NOPCH} ${SRC_HDR} 
	${SRC_QT} ${SRC_QT_HDR_NOMOC} ${SRC_QT_HDR} ${MOC_SOURCES} 
	${SRC_QT_RES} ${SRC_QT_RES_GEN} ${SRC_QT_RES_FILES})
CREATE_PCH(uiRunner ${SRC_DIR}/uiRunner/pch.hpp ${SRC_PCH})
USE_PCH(uiRunner ${SRC_DIR}/uiRunner/pch.hpp ${SRC})
USE_PCH(uiRunner ${SRC_DIR}/uiRunner/pch.hpp ${SRC_QT})

SETUP_BIN_OUT(uiRunner client)

TARGET_LINK_LIBRARIES(uiRunner libheap libutils libpluma libasync liblog)

IF(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG)
	TARGET_LINK_LIBRARIES(uiRunner ${Boost_LIBRARIES})
ENDIF()

IF(UNIX)
	SET(CMAKE_THREAD_PREFER_PTHREAD ON)
	INCLUDE(FindThreads)
	TARGET_LINK_LIBRARIES(uiRunner ${CMAKE_THREAD_LIBS_INIT})
ENDIF()

TARGET_LINK_LIBRARIES(uiRunner ${QT_LIBRARIES})
