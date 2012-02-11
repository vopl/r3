PROJECT (victim)


SET(SRC
	${SRC_DIR}/victim/entry.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_HDR
	${SRC_DIR}/victim/pch.hpp
)
SOURCE_GROUP(src FILES ${SRC_HDR})

SET(SRC_NOPCH
	${SRC_DIR}/heapNewDelete.cpp
)

IF(MSVC)
	SET(SRC_PCH ${SRC_DIR}/victim/pch.cpp)
	SOURCE_GROUP(src FILES ${SRC_PCH})
ENDIF()

ADD_EXECUTABLE(victim ${SRC_STUB} ${SRC} ${SRC_NOPCH} ${SRC_HDR} ${SRC_PCH})
CREATE_PCH(victim ${SRC_DIR}/victim/pch.hpp ${SRC_PCH})
USE_PCH(victim ${SRC_DIR}/victim/pch.hpp ${SRC})

SETUP_BIN_OUT(victim server)

TARGET_LINK_LIBRARIES(victim libheap libutils libpluma liblog)


IF(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG)
	TARGET_LINK_LIBRARIES(victim ${Boost_LIBRARIES})
ENDIF()
