PROJECT (server)

SET(INCLUDE
	${INC_DIR}/server/iserver.hpp
	${INC_DIR}/server/isession.hpp
	${INC_DIR}/server/isessionManager.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/server/server.cpp
	${SRC_DIR}/server/plug.cpp
	${SRC_DIR}/server/session.cpp
	${SRC_DIR}/server/sessionManager.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_NOPCH
	${SRC_DIR}/plumaNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})

SET(SRC_HDR
	${SRC_DIR}/server/server.hpp
	${SRC_DIR}/server/session.hpp
	${SRC_DIR}/server/sessionManager.hpp
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

IF(LINUX)
	SET(CMAKE_THREAD_PREFER_PTHREAD ON)
	INCLUDE(FindThreads)
	TARGET_LINK_LIBRARIES(entry ${CMAKE_THREAD_LIBS_INIT})
	TARGET_LINK_LIBRARIES(entry ${Boost_LIBRARIES})
ENDIF()