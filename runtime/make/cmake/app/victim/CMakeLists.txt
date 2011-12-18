PROJECT (victim)


SET(SRC
	${SRC_DIR}/victim/entry.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_HDR
	${SRC_DIR}/victim/pch.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})

SET(SRC_NOPCH
	${SRC_DIR}/heapNewDelete.cpp
)
SET(SRC_PCH
	${SRC_DIR}/victim/pch.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})


PRESETUP_BIN_OUT(SRC_STUB)
ADD_EXECUTABLE(victim ${SRC_STUB} ${SRC} ${SRC_NOPCH} ${SRC_HDR} ${SRC_PCH})
CREATE_PCH(victim ${SRC_DIR}/victim/pch.h ${SRC_PCH})
USE_PCH(victim ${SRC_DIR}/victim/pch.h ${SRC})
SETUP_BIN_OUT(victim server)

TARGET_LINK_LIBRARIES(victim libheap libutils libpluma liblog)

