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


ADD_EXECUTABLE(victim ${SRC_STUB} ${SRC} ${SRC_NOPCH} ${SRC_HDR} ${SRC_PCH})
CREATE_PCH(victim ${SRC_DIR}/victim/pch.h ${SRC_PCH})
USE_PCH(victim ${SRC_DIR}/victim/pch.h ${SRC})

SET_TARGET_PROPERTIES(victim
	PROPERTIES RUNTIME_OUTPUT_DIRECTORY
	${SERVERBIN_DIR})

TARGET_LINK_LIBRARIES(victim libheap libutils libpluma liblog)


IF(CMAKE_COMPILER_IS_GNUCXX)
	TARGET_LINK_LIBRARIES(victim ${Boost_LIBRARIES})
ENDIF()
