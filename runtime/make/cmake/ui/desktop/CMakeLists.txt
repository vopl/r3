PROJECT (desktop)

SET(SRC
	main.js

	comp1/main.js
	comp1/main.ui
)

SET(SRC_PREP)
FOREACH(f ${SRC})
	GET_FILENAME_COMPONENT(lpath ${f} PATH)
	GET_FILENAME_COMPONENT(ext ${f} EXT)

	SET(in ${UI_DIR}/desktop/${f})
	GET_FILENAME_COMPONENT(in ${in} ABSOLUTE)

	SOURCE_GROUP(src\\${lpath} FILES ${in})



	IF(${ext} STREQUAL ".js")
	ENDIF()


	IF(${ext} STREQUAL ".ui")

		SET(out "${in}.js")
		SOURCE_GROUP("generated\\${lpath}" FILES ${out})

		ADD_CUSTOM_COMMAND(
			OUTPUT ${out}
			MAIN_DEPENDENCY ${in}
			COMMAND echo ARGS "gen ${in} -> ${out}")
	ENDIF()



	SET(SRC_PREP ${SRC_PREP} ${in} ${out})
	#MESSAGE("${in}, ${out}")
ENDFOREACH()

ADD_CUSTOM_TARGET(desktop
	COMMAND echo  build desktop
	SOURCES ${SRC_PREP})
