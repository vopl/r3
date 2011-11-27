PROJECT (server)


SET(SRC
	${SRC_DIR}/server/entry.cpp
	${SRC_DIR}/heapNewDelete.cpp
)

PRESETUP_BIN_OUT(SRC_STUB)
ADD_EXECUTABLE(server ${SRC_STUB} ${SRC})
SETUP_BIN_OUT(server bin)

TARGET_LINK_LIBRARIES(server libheap libpluma)

