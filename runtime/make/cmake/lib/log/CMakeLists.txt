PROJECT (log)


set (INCLUDE
	${INC_DIR}/log/api.h
	${INC_DIR}/log/client.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

set (SRC
	${SRC_DIR}/heapNewDelete.cpp
	${SRC_DIR}/log/rootInitializer.cpp
)
SOURCE_GROUP(src FILES ${SRC})



ADD_LIBRARY(liblog SHARED ${SRC_STUB} ${INCLUDE} ${SRC})
SET_TARGET_PROPERTIES(liblog PROPERTIES PREFIX "" IMPORT_PREFIX "")

SETUP_BIN_OUT(liblog server)
SETUP_BIN_OUT(liblog client)

find_library(l4cpl log4cplus)
find_library(l4cpld log4cplusd)

IF("l4cpl-NOTFOUND" STREQUAL "${l4cpl}")
	MESSAGE(FATAL_ERROR "log4cplus library not found")
ENDIF()

IF("l4cpld-NOTFOUND" STREQUAL "${l4cpld}")
	MESSAGE("log4cplus library not found in debug mode, will use release")
	SET(l4cpld ${l4cpl})
ENDIF()

SET(l4cpl optimized ${l4cpl} debug ${l4cpld})

MESSAGE(STATUS "Found log4cplus ${l4cpl}")

target_link_libraries (liblog libheap ${l4cpl})

