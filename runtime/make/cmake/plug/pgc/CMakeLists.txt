PROJECT (plugpgc)

SET(INCLUDE
	${INC_DIR}/pgc/idb.hpp
	${INC_DIR}/pgc/iconnection.hpp
	${INC_DIR}/pgc/istatement.hpp
	${INC_DIR}/pgc/iresult.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/pgc/plug.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_NOPCH
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})

SET(SRC_HDR
	${SRC_DIR}/pgc/pch.h
	
)
SOURCE_GROUP(src FILES ${SRC_HDR})


SET(SRC_PCH
	${SRC_DIR}/pgc/pch.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})






FIND_PACKAGE(PostgreSQL REQUIRED)
INCLUDE_DIRECTORIES(${PostgreSQL_INCLUDE_DIRS})







PRESETUP_BIN_OUT(SRC_STUB)
ADD_LIBRARY(plugpgc SHARED ${SRC_STUB} ${INCLUDE} ${SRC} ${SRC_NOPCH} ${SRC_HDR} ${SRC_PCH})
CREATE_PCH(plugpgc ${SRC_DIR}/pgc/pch.h ${SRC_PCH})
USE_PCH(plugpgc ${SRC_DIR}/pgc/pch.h ${SRC})
SETUP_BIN_OUT(plugpgc plug)

TARGET_LINK_LIBRARIES(plugpgc libheap libpluma libutils)
TARGET_LINK_LIBRARIES(plugpgc ${PostgreSQL_LIBRARIES})
