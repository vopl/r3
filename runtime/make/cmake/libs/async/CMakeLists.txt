PROJECT (async)

SET(INCLUDE
	${INC_DIR}/async/service.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/async/service.cpp
	${SRC_DIR}/async/serviceImpl.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_HDR
	${SRC_DIR}/async/serviceImpl.hpp
	${SRC_DIR}/async/cmaHandler.hpp
	${SRC_DIR}/async/pch.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})


SET(SRC_PCH
	${SRC_DIR}/async/pch.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})


PRESETUP_BIN_OUT(SRC_STUB)
	ADD_LIBRARY(async STATIC ${SRC_STUB} ${INCLUDE} ${SRC} ${SRC_HDR} ${SRC_PCH})
	CREATE_PCH(async ${SRC_DIR}/async/pch.h ${SRC_PCH})
	USE_PCH(async ${SRC_DIR}/async/pch.h ${SRC})
SETUP_BIN_OUT(async lib)

TARGET_LINK_LIBRARIES(async utils)
