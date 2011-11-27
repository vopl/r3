PROJECT (entry)


SET(SRC
	${SRC_DIR}/entry/main.cpp
	${SRC_DIR}/plumaNewDelete.cpp
)

PRESETUP_BIN_OUT(SRC_STUB)
ADD_EXECUTABLE(entry ${SRC_STUB} ${SRC})
SETUP_BIN_OUT(entry bin)

TARGET_LINK_LIBRARIES(entry pluma)
