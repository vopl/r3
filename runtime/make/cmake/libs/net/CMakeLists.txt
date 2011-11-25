PROJECT (net)

SET(INCLUDE
	${INC_DIR}/net/channel.hpp
	${INC_DIR}/net/clientSession.hpp
	${INC_DIR}/net/connector.hpp
	${INC_DIR}/net/serverSession.hpp
	${INC_DIR}/net/serverSessionManager.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/net/channel.cpp
	${SRC_DIR}/net/channelHubImpl.cpp
	${SRC_DIR}/net/channelSocketImpl.cpp
	${SRC_DIR}/net/clientSession.cpp
	${SRC_DIR}/net/clientSessionImpl.cpp
	${SRC_DIR}/net/connector.cpp
	${SRC_DIR}/net/connectorImpl.cpp
	${SRC_DIR}/net/serverSession.cpp
	${SRC_DIR}/net/serverSessionImpl.cpp
	${SRC_DIR}/net/serverSessionManager.cpp
	${SRC_DIR}/net/serverSessionManagerImpl.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_HDR
	${SRC_DIR}/net/channelImpl.hpp
	${SRC_DIR}/net/serverSessionImpl.hpp
	${SRC_DIR}/net/serverSessionManagerImpl.hpp
	${SRC_DIR}/net/connectorImpl.hpp
	${SRC_DIR}/net/channelHubImpl.hpp
	${SRC_DIR}/net/channelSocketImpl.hpp
	${SRC_DIR}/net/clientSessionImpl.hpp
	${SRC_DIR}/net/pch.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})


SET(SRC_PCH
	${SRC_DIR}/net/pch.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})


PRESETUP_BIN_OUT(SRC_STUB)
	ADD_LIBRARY(net STATIC ${SRC_STUB} ${INCLUDE} ${SRC} ${SRC_HDR} ${SRC_PCH})
	CREATE_PCH(net ${SRC_DIR}/net/pch.h ${SRC_PCH})
	USE_PCH(net ${SRC_DIR}/net/pch.h ${SRC})
SETUP_BIN_OUT(net lib)

TARGET_LINK_LIBRARIES(net async utils)
