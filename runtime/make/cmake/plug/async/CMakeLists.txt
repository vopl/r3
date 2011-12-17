PROJECT (plugasync)

SET(INCLUDE
	${INC_DIR}/async/iservice.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(SRC
	${SRC_DIR}/async/service.cpp
	${SRC_DIR}/async/serviceWorker.cpp
	${SRC_DIR}/async/plug.cpp
	${SRC_DIR}/async/fiber.cpp
	${SRC_DIR}/async/fiberRoot.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_NOPCH
	${SRC_DIR}/heapNewDelete.cpp
)
SOURCE_GROUP(src FILES ${SRC_NOPCH})

SET(SRC_HDR
	${SRC_DIR}/async/service.hpp
	${SRC_DIR}/async/serviceWorker.hpp
	${SRC_DIR}/async/cmaHandler.hpp
	${SRC_DIR}/async/pch.h
	${SRC_DIR}/async/fiber.hpp
	${SRC_DIR}/async/fiberRoot.hpp
)
SOURCE_GROUP(src FILES ${SRC_HDR})


SET(SRC_PCH
	${SRC_DIR}/async/pch.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})



PRESETUP_BIN_OUT(SRC_STUB)
ADD_LIBRARY(plugasync SHARED ${SRC_STUB} ${INCLUDE} ${SRC} ${SRC_NOPCH} ${SRC_HDR} ${SRC_PCH})
CREATE_PCH(plugasync ${SRC_DIR}/async/pch.h ${SRC_PCH})
USE_PCH(plugasync ${SRC_DIR}/async/pch.h ${SRC})
SETUP_BIN_OUT(plugasync plug)

TARGET_LINK_LIBRARIES(plugasync libheap libpluma libutils liblog)

IF(LINUX)
	SET(CMAKE_THREAD_PREFER_PTHREAD ON)
	INCLUDE(FindThreads)
	TARGET_LINK_LIBRARIES(plugasync ${CMAKE_THREAD_LIBS_INIT})
	TARGET_LINK_LIBRARIES(plugasync ${Boost_LIBRARIES})
ENDIF()