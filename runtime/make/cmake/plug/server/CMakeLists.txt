PROJECT (server)

SET(INCLUDE
	${INC_DIR}/server/iserver.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/server/server.cpp
	${SRC_DIR}/server/plug.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_NOPCH
	${SRC_DIR}/plumaNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})

SET(SRC_HDR
	${SRC_DIR}/server/server.hpp
	${SRC_DIR}/server/pch.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})


SET(SRC_PCH
	${SRC_DIR}/server/pch.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})


PRESETUP_BIN_OUT(SRC_STUB)
	ADD_LIBRARY(server SHARED ${SRC_STUB} ${INCLUDE} ${SRC} ${SRC_NOPCH} ${SRC_HDR} ${SRC_PCH})
	CREATE_PCH(server ${SRC_DIR}/server/pch.h ${SRC_PCH})
	USE_PCH(server ${SRC_DIR}/server/pch.h ${SRC})
SETUP_BIN_OUT(server plug)

TARGET_LINK_LIBRARIES(server pluma utils)
