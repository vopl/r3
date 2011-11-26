PROJECT (net)

SET(INCLUDE
	${INC_DIR}/net/ichannel.hpp
	${INC_DIR}/net/iclientSession.hpp
	${INC_DIR}/net/iconnector.hpp
	${INC_DIR}/net/iserverSession.hpp
	${INC_DIR}/net/iserverSessionManager.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/net/channelSocket.cpp
	${SRC_DIR}/net/clientSession.cpp
	${SRC_DIR}/net/clientSession.cpp
	${SRC_DIR}/net/connector.cpp
	${SRC_DIR}/net/serverSession.cpp
	${SRC_DIR}/net/serverSessionManager.cpp
	${SRC_DIR}/net/plug.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_NOPCH
	${SRC_DIR}/plumaNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})

SET(SRC_HDR
	${SRC_DIR}/net/serverSession.hpp
	${SRC_DIR}/net/serverSessionManager.hpp
	${SRC_DIR}/net/connector.hpp
	${SRC_DIR}/net/channelHub.hpp
	${SRC_DIR}/net/channelSocket.hpp
	${SRC_DIR}/net/clientSession.hpp
	${SRC_DIR}/net/pch.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})


SET(SRC_PCH
	${SRC_DIR}/net/pch.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})


PRESETUP_BIN_OUT(SRC_STUB)
	ADD_LIBRARY(net SHARED ${SRC_STUB} ${INCLUDE} ${SRC} ${SRC_NOPCH} ${SRC_HDR} ${SRC_PCH})
	CREATE_PCH(net ${SRC_DIR}/net/pch.h ${SRC_PCH})
	USE_PCH(net ${SRC_DIR}/net/pch.h ${SRC})
SETUP_BIN_OUT(net plug)

TARGET_LINK_LIBRARIES(net pluma utils)


INCLUDE(FindOpenSSL.cmake)
IF(NOT OPENSSL_FOUND)
	MESSAGE(FATAL_ERROR "OpenSSL required")
ENDIF()
INCLUDE_DIRECTORIES(${OPENSSL_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(net ${OPENSSL_LIBRARIES})
