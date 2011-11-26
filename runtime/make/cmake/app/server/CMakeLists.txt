PROJECT (server)


SET(SRC
	${SRC_DIR}/server/main.cpp
	${SRC_DIR}/plumaNewDelete.cpp
)

PRESETUP_BIN_OUT(SRC_STUB)
ADD_EXECUTABLE(server ${SRC_STUB} ${SRC})
SETUP_BIN_OUT(server bin)

TARGET_LINK_LIBRARIES(server pluma)
