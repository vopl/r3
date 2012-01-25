PROJECT (plugnet)

SET(INCLUDE
	${INC_DIR}/net/ichannel.hpp
	${INC_DIR}/net/iacceptor.hpp
	${INC_DIR}/net/iconnector.hpp
	${INC_DIR}/net/channelHub.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/net/channelSocket.cpp
	${SRC_DIR}/net/connector.cpp
	${SRC_DIR}/net/acceptor.cpp
	${SRC_DIR}/net/plug.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_NOPCH
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})

SET(SRC_HDR
	${SRC_DIR}/net/connector.hpp
	${SRC_DIR}/net/acceptor.hpp
	${SRC_DIR}/net/channelSocket.hpp
	${SRC_DIR}/net/pch.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})


SET(SRC_PCH
	${SRC_DIR}/net/pch.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})


ADD_LIBRARY(plugnet SHARED ${SRC_STUB} ${INCLUDE} ${SRC} ${SRC_NOPCH} ${SRC_HDR} ${SRC_PCH})
SET_TARGET_PROPERTIES(plugnet PROPERTIES PREFIX "" IMPORT_PREFIX "")

CREATE_PCH(plugnet ${SRC_DIR}/net/pch.h ${SRC_PCH})
USE_PCH(plugnet ${SRC_DIR}/net/pch.h ${SRC})

SETUP_BIN_OUT(plugnet plug)

TARGET_LINK_LIBRARIES(plugnet libheap libpluma libutils libasync)


INCLUDE(FindOpenSSL)
IF(NOT OPENSSL_FOUND)
	MESSAGE(FATAL_ERROR "OpenSSL required")
ENDIF()
INCLUDE_DIRECTORIES(${OPENSSL_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(plugnet ${OPENSSL_LIBRARIES})

IF(LINUX)
	TARGET_LINK_LIBRARIES(plugnet ${Boost_LIBRARIES})
	SET(CMAKE_THREAD_PREFER_PTHREAD ON)
	INCLUDE(FindThreads)
	TARGET_LINK_LIBRARIES(plugnet ${CMAKE_THREAD_LIBS_INIT})
ENDIF()


IF(CMAKE_COMPILER_IS_GNUCXX AND WINDOWS)
	TARGET_LINK_LIBRARIES(plugnet Mswsock.lib)
ENDIF()