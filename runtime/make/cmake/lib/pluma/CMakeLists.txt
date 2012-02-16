PROJECT (libpluma)

SET(INCLUDE
	${INC_DIR}/pluma/config.hpp
	${INC_DIR}/pluma/connector.hpp
	${INC_DIR}/pluma/host.hpp
	${INC_DIR}/pluma/pluginManager.hpp
	${INC_DIR}/pluma/pluma.hpp
	${INC_DIR}/pluma/pluma.inl
	${INC_DIR}/pluma/provider.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/pluma/dir.cpp
	${SRC_DIR}/pluma/dLibrary.cpp
	${SRC_DIR}/pluma/host.cpp
	${SRC_DIR}/pluma/pluginManager.cpp
	${SRC_DIR}/pluma/provider.cpp
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_HDR
	${SRC_DIR}/pluma/dir.hpp
	${SRC_DIR}/pluma/dLibrary.hpp
	${SRC_DIR}/pluma/uce-dirent.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})


ADD_DEFINITIONS(-DPLUMA_EXPORTS)

ADD_LIBRARY(libpluma SHARED ${INCLUDE} ${SRC} ${SRC_HDR})
SET_TARGET_PROPERTIES(libpluma PROPERTIES PREFIX "" IMPORT_PREFIX "")

SETUP_BIN_OUT(libpluma server)
SETUP_BIN_OUT(libpluma client)

TARGET_LINK_LIBRARIES(libpluma libheap)

IF(LINUX)
	TARGET_LINK_LIBRARIES(libpluma dl)
ENDIF()
