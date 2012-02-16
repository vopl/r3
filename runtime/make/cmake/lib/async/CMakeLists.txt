PROJECT (libasync)

SET(INCLUDE
	${INC_DIR}/async/api.h

	${INC_DIR}/async/service.hpp
	${INC_DIR}/async/exception.hpp

	${INC_DIR}/async/event.hpp
	${INC_DIR}/async/eventWaiter.hpp
	${INC_DIR}/async/mutex.hpp

	${INC_DIR}/async/future.hpp
	${INC_DIR}/async/futureWaiter.hpp

	${INC_DIR}/async/asioBridge.hpp

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
#	${SRC_DIR}/async/ucontext.c
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
	${SRC_DIR}/async/pch.hpp

#	${SRC_DIR}/async/ucontext.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})


IF(MSVC)
	SET(SRC_PCH ${SRC_DIR}/async/pch.cpp)
	SOURCE_GROUP(src FILES ${SRC_PCH})
ENDIF()






INCLUDE(CheckFunctionExists)
INCLUDE(CheckLibraryExists)
INCLUDE(CheckIncludeFiles)
INCLUDE(CheckPrototypeDefinition)
INCLUDE(CheckTypeSize)

CHECK_INCLUDE_FILES (ucontext.h HAVE_UCONTEXT_H)

IF(WINDOWS)
	CHECK_PROTOTYPE_DEFINITION(
		CreateFiberEx
		"LPVOID WINAPI CreateFiberEx(SIZE_T dwStackCommitSize, SIZE_T dwStackReserveSize, DWORD dwFlags, LPFIBER_START_ROUTINE lpStartAddress, LPVOID lpParameter);"
		"NULL"
		windows.h
		HAVE_WINFIBER)
ENDIF()

CHECK_TYPE_SIZE("void *" PVOID_SIZE)
ADD_DEFINITIONS(-D\"PVOID_SIZE=${PVOID_SIZE}\")

CHECK_TYPE_SIZE("int" INT_SIZE)
ADD_DEFINITIONS(-D\"INT_SIZE=${INT_SIZE}\")

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)


INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

ADD_LIBRARY(libasync SHARED ${INCLUDE} ${SRC} ${SRC_NOPCH} ${SRC_HDR} ${SRC_PCH})
SET_TARGET_PROPERTIES(libasync PROPERTIES PREFIX "" IMPORT_PREFIX "")

CREATE_PCH(libasync ${SRC_DIR}/async/pch.hpp ${SRC_PCH})
USE_PCH(libasync ${SRC_DIR}/async/pch.hpp ${SRC})

SETUP_BIN_OUT(libasync server)
SETUP_BIN_OUT(libasync client)

TARGET_LINK_LIBRARIES(libasync libheap libutils liblog)

IF(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG)
	TARGET_LINK_LIBRARIES(libasync ${Boost_LIBRARIES})
ENDIF()

IF(UNIX)
	SET(CMAKE_THREAD_PREFER_PTHREAD ON)
	INCLUDE(FindThreads)
	TARGET_LINK_LIBRARIES(libasync ${CMAKE_THREAD_LIBS_INIT})
ENDIF()
