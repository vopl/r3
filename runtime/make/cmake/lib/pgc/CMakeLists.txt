PROJECT (libpgc)

SET(INCLUDE
	${INC_DIR}/pgc/db.hpp
	${INC_DIR}/pgc/connection.hpp
	${INC_DIR}/pgc/statement.hpp
	${INC_DIR}/pgc/data.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/pgc/db.cpp
	${SRC_DIR}/pgc/dbImpl.cpp
	${SRC_DIR}/pgc/statement.cpp
	${SRC_DIR}/pgc/statementImpl.cpp
	${SRC_DIR}/pgc/data.cpp
	${SRC_DIR}/pgc/dataImpl.cpp
	${SRC_DIR}/pgc/connection.cpp
	${SRC_DIR}/pgc/connectionHolder.cpp
	${SRC_DIR}/pgc/connectionImpl.cpp
	${SRC_DIR}/pgc/bindData.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_NOPCH
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})

SET(SRC_HDR
	${SRC_DIR}/pgc/pch.h
	${SRC_DIR}/pgc/dbImpl.hpp
	${SRC_DIR}/pgc/statementImpl.hpp
	${SRC_DIR}/pgc/dataImpl.hpp
	${SRC_DIR}/pgc/connectionHolder.hpp
	${SRC_DIR}/pgc/connectionImpl.hpp
	${SRC_DIR}/pgc/bindData.hpp
)
SOURCE_GROUP(src FILES ${SRC_HDR})


SET(SRC_PCH
	${SRC_DIR}/pgc/pch.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})






FIND_PACKAGE(PostgreSQL REQUIRED)
INCLUDE_DIRECTORIES(${PostgreSQL_INCLUDE_DIRS})







PRESETUP_BIN_OUT(SRC_STUB)
ADD_LIBRARY(libpgc SHARED ${SRC_STUB} ${INCLUDE} ${SRC} ${SRC_NOPCH} ${SRC_HDR} ${SRC_PCH})
CREATE_PCH(libpgc ${SRC_DIR}/pgc/pch.h ${SRC_PCH})
USE_PCH(libpgc ${SRC_DIR}/pgc/pch.h ${SRC})
SETUP_BIN_OUT(libpgc server)

TARGET_LINK_LIBRARIES(libpgc libheap libutils liblog libasync)
TARGET_LINK_LIBRARIES(libpgc ${PostgreSQL_LIBRARY})
