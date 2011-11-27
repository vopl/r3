PROJECT (async)

SET(INCLUDE
	${INC_DIR}/async/iservice.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/async/service.cpp
	${SRC_DIR}/async/plug.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_NOPCH
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})

SET(SRC_HDR
	${SRC_DIR}/async/service.hpp
	${SRC_DIR}/async/cmaHandler.hpp
	${SRC_DIR}/async/pch.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})


SET(SRC_PCH
	${SRC_DIR}/async/pch.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})


PRESETUP_BIN_OUT(SRC_STUB)
	ADD_LIBRARY(async SHARED ${SRC_STUB} ${INCLUDE} ${SRC} ${SRC_NOPCH} ${SRC_HDR} ${SRC_PCH})
	CREATE_PCH(async ${SRC_DIR}/async/pch.h ${SRC_PCH})
	USE_PCH(async ${SRC_DIR}/async/pch.h ${SRC})
SETUP_BIN_OUT(async plug)

TARGET_LINK_LIBRARIES(async heap pluma utils)

IF(LINUX)
	SET(CMAKE_THREAD_PREFER_PTHREAD ON)
	INCLUDE(FindThreads)
	TARGET_LINK_LIBRARIES(async ${CMAKE_THREAD_LIBS_INIT})
	TARGET_LINK_LIBRARIES(async ${Boost_LIBRARIES})
ENDIF()