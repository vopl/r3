PROJECT (server)


SET(SRC
	${SRC_DIR}/server/entry.cpp
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC})

ADD_EXECUTABLE(server ${SRC})

SETUP_BIN_OUT(server server)

TARGET_LINK_LIBRARIES(server libheap libutils libpluma liblog)

IF(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG)
	TARGET_LINK_LIBRARIES(server ${Boost_LIBRARIES})
ENDIF()

IF(UNIX)
	SET(CMAKE_THREAD_PREFER_PTHREAD ON)
	INCLUDE(FindThreads)
	TARGET_LINK_LIBRARIES(server ${CMAKE_THREAD_LIBS_INIT})
ENDIF()

IF((CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG) AND WINDOWS)
	TARGET_LINK_LIBRARIES(server wsock32)
ENDIF()
