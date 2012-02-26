PROJECT (libpg)

SET(PGC_INCLUDE
	${INC_DIR}/pgc/api.h
	${INC_DIR}/pgc/db.hpp
	${INC_DIR}/pgc/connection.hpp
	${INC_DIR}/pgc/statement.hpp
	${INC_DIR}/pgc/result.hpp
)
SOURCE_GROUP(pgc\\include FILES ${PGC_INCLUDE})

SET(PGC_SRC
	${SRC_DIR}/pgc/db.cpp
	${SRC_DIR}/pgc/dbImpl.cpp
	${SRC_DIR}/pgc/statement.cpp
	${SRC_DIR}/pgc/statementImpl.cpp
	${SRC_DIR}/pgc/result.cpp
	${SRC_DIR}/pgc/resultImpl.cpp
	${SRC_DIR}/pgc/connection.cpp
	${SRC_DIR}/pgc/connectionHolder.cpp
	${SRC_DIR}/pgc/connectionImpl.cpp
	${SRC_DIR}/pgc/bindData.cpp
)
SOURCE_GROUP(pgc\\src FILES ${PGC_SRC})

SET(SRC_NOPCH
	${SRC_DIR}/pgc/pch.hpp
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})

SET(PGC_SRC_HDR
	${SRC_DIR}/pgc/dbImpl.hpp
	${SRC_DIR}/pgc/statementImpl.hpp
	${SRC_DIR}/pgc/resultImpl.hpp
	${SRC_DIR}/pgc/connectionHolder.hpp
	${SRC_DIR}/pgc/connectionImpl.hpp
	${SRC_DIR}/pgc/bindData.hpp
)
SOURCE_GROUP(pgc\\src FILES ${PGC_SRC_HDR})


IF(MSVC)
	SET(SRC_PCH ${SRC_DIR}/pgc/pch.cpp)
	SOURCE_GROUP(src FILES ${SRC_PCH})
ENDIF()

INCLUDE_DIRECTORIES(${SRC_DIR}/pgc)

FIND_PACKAGE(PostgreSQL)
IF(NOT PostgreSQL_FOUND)
	MESSAGE(FATAL_ERROR "PostgreSQL not found")
ENDIF()
#MESSAGE(STATUS "Found PostgreSQL ${PostgreSQL_LIBRARY}")
INCLUDE_DIRECTORIES(${PostgreSQL_INCLUDE_DIRS})

























#########################################################################################
SET(PGS_INCLUDE
	${INC_DIR}/pgs/category.hpp
	${INC_DIR}/pgs/cluster.hpp
	${INC_DIR}/pgs/expression.hpp
	${INC_DIR}/pgs/expressionSugar.hpp
	${INC_DIR}/pgs/statement.hpp
	${INC_DIR}/pgs/field.hpp
	${INC_DIR}/pgs/link.hpp
	${INC_DIR}/pgs/order.hpp
	${INC_DIR}/pgs/result.hpp
	${INC_DIR}/pgs/select.hpp
	${INC_DIR}/pgs/value.hpp
)
SOURCE_GROUP(pgs\\include FILES ${PGS_INCLUDE})

SET(PGS_INCLUDE_META
	${INC_DIR}/pgs/meta/category.hpp
	${INC_DIR}/pgs/meta/cluster.hpp
	${INC_DIR}/pgs/meta/clusterStorage.hpp
	${INC_DIR}/pgs/meta/common.hpp
	${INC_DIR}/pgs/meta/field.hpp
	${INC_DIR}/pgs/meta/fieldScanty.hpp
	${INC_DIR}/pgs/meta/index.hpp
	${INC_DIR}/pgs/meta/ptrContainer.hpp
	${INC_DIR}/pgs/meta/relation.hpp
	${INC_DIR}/pgs/meta/relationEnd.hpp
	${INC_DIR}/pgs/meta/schema.hpp
	${INC_DIR}/pgs/meta/schemaInitializer.hpp
)
SOURCE_GROUP(pgs\\include\\meta FILES ${PGS_INCLUDE_META})

SET(PGS_SRC
	${SRC_DIR}/pgs/category.cpp
	${SRC_DIR}/pgs/categoryImpl.cpp
	${SRC_DIR}/pgs/cluster.cpp
	${SRC_DIR}/pgs/clusterImpl.cpp
	${SRC_DIR}/pgs/expression.cpp
	${SRC_DIR}/pgs/expressionImpl.cpp
	${SRC_DIR}/pgs/expressionSugar.cpp
	${SRC_DIR}/pgs/statement.cpp
	${SRC_DIR}/pgs/statementImpl.cpp
	${SRC_DIR}/pgs/field.cpp
	${SRC_DIR}/pgs/fieldImpl.cpp
	${SRC_DIR}/pgs/link.cpp
	${SRC_DIR}/pgs/linkImpl.cpp
	${SRC_DIR}/pgs/order.cpp
	${SRC_DIR}/pgs/orderImpl.cpp
	${SRC_DIR}/pgs/result.cpp
	${SRC_DIR}/pgs/resultImpl.cpp
	${SRC_DIR}/pgs/sdHelpers.cpp
	${SRC_DIR}/pgs/select.cpp
	${SRC_DIR}/pgs/selectImpl.cpp
	${SRC_DIR}/pgs/value.cpp
	${SRC_DIR}/pgs/valueImpl.cpp
)
SOURCE_GROUP(pgs\\src FILES ${PGS_SRC})

SET(PGS_SRC_META
	${SRC_DIR}/pgs/meta/cluster.cpp
	${SRC_DIR}/pgs/meta/clusterImpl.cpp
)
SOURCE_GROUP(pgs\\src\\meta FILES ${PGS_SRC_META})


SET(PGS_SRC_HDR
	${SRC_DIR}/pgs/categoryImpl.hpp
	${SRC_DIR}/pgs/clusterImpl.hpp
	${SRC_DIR}/pgs/expressionImpl.hpp
	${SRC_DIR}/pgs/statementImpl.hpp
	${SRC_DIR}/pgs/fieldImpl.hpp
	${SRC_DIR}/pgs/instantiate4pgctypes.hpp
	${SRC_DIR}/pgs/linkImpl.hpp
	${SRC_DIR}/pgs/orderImpl.hpp
	${SRC_DIR}/pgs/resultImpl.hpp
	${SRC_DIR}/pgs/sdHelpers.hpp
	${SRC_DIR}/pgs/selectImpl.hpp
	${SRC_DIR}/pgs/valueImpl.hpp
)
SOURCE_GROUP(pgs\\src FILES ${PGS_SRC_HDR})

SET(PGS_SRC_META_HDR
	${SRC_DIR}/pgs/meta/clusterImpl.hpp
)
SOURCE_GROUP(pgs\\src\\meta FILES ${PGS_SRC_META_HDR})





INCLUDE_DIRECTORIES(${SRC_DIR}/pgs)





INCLUDE_DIRECTORIES(${SRC_DIR})







ADD_LIBRARY(libpg SHARED 
	${SRC_NOPCH} 
	${SRC_PCH} 

	${PGC_INCLUDE} 
	${PGC_SRC} 
	${PGC_SRC_HDR} 

	${PGS_INCLUDE} 
	${PGS_INCLUDE_META} 
	${PGS_SRC} 
	${PGS_SRC_META} 
	${PGS_SRC_HDR} 
	${PGS_SRC_META_HDR})
SET_TARGET_PROPERTIES(libpg PROPERTIES PREFIX "" IMPORT_PREFIX "")
	
CREATE_PCH(libpg ${SRC_DIR}/pgc/pch.hpp ${SRC_PCH})
USE_PCH(libpg ${SRC_DIR}/pgc/pch.hpp ${PGC_SRC})
USE_PCH(libpg ${SRC_DIR}/pgc/pch.hpp ${PGS_SRC})
USE_PCH(libpg ${SRC_DIR}/pgc/pch.hpp ${PGS_SRC_META})


SETUP_BIN_OUT(libpg server)

TARGET_LINK_LIBRARIES(libpg libheap libutils liblog libasync)
TARGET_LINK_LIBRARIES(libpg ${PostgreSQL_LIBRARY})

IF(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG)
	TARGET_LINK_LIBRARIES(libpg ${Boost_LIBRARIES})
ENDIF()

IF((CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG) AND WINDOWS)
	TARGET_LINK_LIBRARIES(libpg wsock32 ws2_32)
ENDIF()
