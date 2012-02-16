PROJECT (plugclient)

SET(INCLUDE
	${INC_DIR}/client/iclient.hpp
	${INC_DIR}/client/isession.hpp
	${INC_DIR}/client/iagent.hpp
	${INC_DIR}/client/endpoint.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/client/client.cpp
	${SRC_DIR}/client/plug.cpp
	${SRC_DIR}/client/session.cpp
	${SRC_DIR}/client/agent.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_NOPCH
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})

SET(SRC_HDR
	${SRC_DIR}/client/client.hpp
	${SRC_DIR}/client/session.hpp
	${SRC_DIR}/client/agent.hpp
	${SRC_DIR}/client/pch.hpp
)
SOURCE_GROUP(src FILES ${SRC_HDR})


IF(MSVC)
	SET(SRC_PCH ${SRC_DIR}/client/pch.cpp)
	SOURCE_GROUP(src FILES ${SRC_PCH})
ENDIF()


ADD_LIBRARY(plugclient SHARED ${INCLUDE} ${SRC} ${SRC_NOPCH} ${SRC_HDR} ${SRC_PCH})
SET_TARGET_PROPERTIES(plugclient PROPERTIES PREFIX "" IMPORT_PREFIX "")

CREATE_PCH(plugclient ${SRC_DIR}/client/pch.hpp ${SRC_PCH})
USE_PCH(plugclient ${SRC_DIR}/client/pch.hpp ${SRC})

SETUP_BIN_OUT(plugclient plug)

TARGET_LINK_LIBRARIES(plugclient libheap libpluma libutils liblog libasync)
