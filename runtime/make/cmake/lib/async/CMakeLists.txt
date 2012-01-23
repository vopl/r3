PROJECT (libasync)

SET(INCLUDE
	${INC_DIR}/async/service.hpp
	${INC_DIR}/async/exception.hpp

	${INC_DIR}/async/event.hpp
	${INC_DIR}/async/eventWaiter.hpp
	${INC_DIR}/async/mutex.hpp

	${INC_DIR}/async/future.hpp
	${INC_DIR}/async/futureWaiter.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/async/service.cpp
	${SRC_DIR}/async/event.cpp
	${SRC_DIR}/async/mutex.cpp

	${SRC_DIR}/async/serviceImpl.cpp
	${SRC_DIR}/async/workerImpl.cpp
	${SRC_DIR}/async/fiberImpl.cpp
	${SRC_DIR}/async/fiberRootImpl.cpp

	${SRC_DIR}/async/eventImpl.cpp
	${SRC_DIR}/async/mutexImpl.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_NOPCH
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})

SET(SRC_HDR
	${SRC_DIR}/async/serviceImpl.hpp
	${SRC_DIR}/async/workerImpl.hpp
	${SRC_DIR}/async/fiberImpl.hpp
	${SRC_DIR}/async/fiberRootImpl.hpp
	${SRC_DIR}/async/threadLocalStorage.hpp
	${SRC_DIR}/async/fiberPool.hpp

	${SRC_DIR}/async/eventImpl.hpp
	${SRC_DIR}/async/mutexImpl.hpp

	${SRC_DIR}/async/cmaHandler.hpp
	${SRC_DIR}/async/pch.h
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

IF(CMAKE_COMPILER_IS_GNUCXX)
	TARGET_LINK_LIBRARIES(libasync ${Boost_LIBRARIES})
ENDIF()

IF(LINUX)
	SET(CMAKE_THREAD_PREFER_PTHREAD ON)
	INCLUDE(FindThreads)
	TARGET_LINK_LIBRARIES(libasync ${CMAKE_THREAD_LIBS_INIT})
ENDIF()