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
	${SRC_DIR}/client/pch.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})


SET(SRC_PCH
	${SRC_DIR}/client/pch.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})


ADD_LIBRARY(plugclient SHARED ${SRC_STUB} ${INCLUDE} ${SRC} ${SRC_NOPCH} ${SRC_HDR} ${SRC_PCH})
CREATE_PCH(plugclient ${SRC_DIR}/client/pch.h ${SRC_PCH})
USE_PCH(plugclient ${SRC_DIR}/client/pch.h ${SRC})

SET_TARGET_PROPERTIES(plugclient PROPERTIES 
	RUNTIME_OUTPUT_DIRECTORY ${PLUG_DIR}
	LIBRARY_OUTPUT_DIRECTORY ${PLUG_DIR})

TARGET_LINK_LIBRARIES(plugclient libheap libpluma libutils liblog libasync)
