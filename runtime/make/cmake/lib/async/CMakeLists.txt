PROJECT (libasync)

SET(INCLUDE
	${INC_DIR}/async/iservice.hpp
	${INC_DIR}/async/fiber.hpp
	${INC_DIR}/async/worker.hpp
	${INC_DIR}/async/workerHandler.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/async/service.cpp
	${SRC_DIR}/async/plug.cpp
	${SRC_DIR}/async/worker.cpp
	${SRC_DIR}/async/fiber.cpp

	${SRC_DIR}/async/workerImpl.cpp
	${SRC_DIR}/async/fiberImpl.cpp
	${SRC_DIR}/async/fiberRootImpl.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_NOPCH
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})

SET(SRC_HDR
	${SRC_DIR}/async/service.hpp
	${SRC_DIR}/async/cmaHandler.hpp
	${SRC_DIR}/async/pch.h
	${SRC_DIR}/async/workerImpl.hpp
	${SRC_DIR}/async/fiberImpl.hpp
	${SRC_DIR}/async/fiberRootImpl.hpp
	${SRC_DIR}/async/threadLocalStorage.hpp
)
SOURCE_GROUP(src FILES ${SRC_HDR})


SET(SRC_PCH
	${SRC_DIR}/async/pch.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})



PRESETUP_BIN_OUT(SRC_STUB)
ADD_LIBRARY(libasync SHARED ${SRC_STUB} ${INCLUDE} ${SRC} ${SRC_NOPCH} ${SRC_HDR} ${SRC_PCH})
CREATE_PCH(libasync ${SRC_DIR}/async/pch.h ${SRC_PCH})
USE_PCH(libasync ${SRC_DIR}/async/pch.h ${SRC})
SETUP_BIN_OUT(libasync server)
SETUP_BIN_OUT(libasync client)

TARGET_LINK_LIBRARIES(libasync libheap libutils liblog)

IF(LINUX)
	SET(CMAKE_THREAD_PREFER_PTHREAD ON)
	INCLUDE(FindThreads)
	TARGET_LINK_LIBRARIES(libasync ${CMAKE_THREAD_LIBS_INIT})
	TARGET_LINK_LIBRARIES(libasync ${Boost_LIBRARIES})
ENDIF()