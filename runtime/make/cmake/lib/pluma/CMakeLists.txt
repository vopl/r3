PROJECT (pluma)

SET(INCLUDE
	${INC_DIR}/pluma/config.hpp
	${INC_DIR}/pluma/connector.hpp
	${INC_DIR}/pluma/host.hpp
	${INC_DIR}/pluma/pluginManager.hpp
	${INC_DIR}/pluma/pluma.hpp
	${INC_DIR}/pluma/pluma.inl
	${INC_DIR}/pluma/provider.hpp
	${INC_DIR}/pluma/heap.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/pluma/dir.cpp
	${SRC_DIR}/pluma/dLibrary.cpp
	${SRC_DIR}/pluma/host.cpp
	${SRC_DIR}/pluma/pluginManager.cpp
	${SRC_DIR}/pluma/provider.cpp
	${SRC_DIR}/pluma/heap.cpp
	${SRC_DIR}/plumaNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_HDR
	${SRC_DIR}/pluma/dir.hpp
	${SRC_DIR}/pluma/dLibrary.hpp
	${SRC_DIR}/pluma/uce-dirent.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})


ADD_DEFINITIONS(-DPLUMA_EXPORTS)

PRESETUP_BIN_OUT(SRC_STUB)
	ADD_LIBRARY(pluma SHARED ${SRC_STUB} ${INCLUDE} ${SRC} ${SRC_HDR})
SETUP_BIN_OUT(pluma bin)

IF(LINUX)
	TARGET_LINK_LIBRARIES(pluma dl)
ENDIF()
