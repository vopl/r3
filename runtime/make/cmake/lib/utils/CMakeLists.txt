PROJECT (libutils)

SET(INCLUDE
	${INC_DIR}/utils/api.h
	${INC_DIR}/utils/aton.hpp
	${INC_DIR}/utils/xton.hpp
	${INC_DIR}/utils/base64.h
	${INC_DIR}/utils/crc32.hpp
	${INC_DIR}/utils/dateTimeDuration.hpp
	${INC_DIR}/utils/fixEndian.hpp
	${INC_DIR}/utils/implAccess.hpp
	${INC_DIR}/utils/julian.h
	${INC_DIR}/utils/ntoa.hpp
	${INC_DIR}/utils/streambufOnArray.hpp
	${INC_DIR}/utils/variant.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

FIND_PROGRAM(ANTLR NAMES antlr antlr.sh antlr.com antlr.exe antlr.bat antlr3 antlr3.sh antlr3.com antlr3.exe antlr3.bat)
IF("${ANTLR}" STREQUAL "ANTLR-NOTFOUND")
	MESSAGE(FATAL_ERROR "antlr 3 required, see http://www.antlr.org/")
ENDIF()
MESSAGE(STATUS "Found antlr: ${ANTLR}")


INCLUDE(CheckIncludeFileCXX)
CHECK_INCLUDE_FILE_CXX(antlr3.hpp HAVE_ANTLR3_HPP)

IF("${HAVE_ANTLR3_HPP}" STREQUAL "")
	MESSAGE(FATAL_ERROR "antlr 3 c++ runtime required, see http://www.antlr.org/")
ENDIF()



ADD_CUSTOM_COMMAND(
	OUTPUT 
		${SRC_DIR}/utils/VariantParser.cpp 
		${SRC_DIR}/utils/VariantParser.hpp 
		${SRC_DIR}/utils/VariantLexer.cpp 
		${SRC_DIR}/utils/VariantLexer.hpp 
	COMMAND 
		${ANTLR} 
	ARGS 
		${SRC_DIR}/utils/Variant.g -o ${SRC_DIR}/utils
	MAIN_DEPENDENCY 
		${SRC_DIR}/utils/Variant.g
	VERBATIM)

SET(SRC
	${SRC_DIR}/utils/base64.cpp
	${SRC_DIR}/utils/crc32.cpp
	${SRC_DIR}/utils/variant.cpp
	${SRC_DIR}/utils/variantLoad.cpp
	${SRC_DIR}/utils/variantLoad2.cpp
	${SRC_DIR}/utils/variantLoadScope.cpp
	${SRC_DIR}/utils/variantLoadScope2.cpp
	${SRC_DIR}/utils/variantLoadGrammar.cpp
	${SRC_DIR}/utils/variantSerialization.cpp
	
	
	${SRC_DIR}/utils/VariantLexer.cpp
	${SRC_DIR}/utils/VariantParser.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_HDR
	${SRC_DIR}/utils/variantDumper.hpp
	${SRC_DIR}/utils/variantImpl.hpp
	${SRC_DIR}/utils/variantLoadScope.hpp
	${SRC_DIR}/utils/variantLoadScope2.hpp
	${SRC_DIR}/utils/variantLoadGrammar.hpp
	${SRC_DIR}/utils/variantConvertMatrix.hpp
	${SRC_DIR}/utils/pch.hpp

	${SRC_DIR}/utils/VariantLexer.hpp
	${SRC_DIR}/utils/VariantParser.hpp
	
	${SRC_DIR}/utils/Variant.g
	
)
SOURCE_GROUP(src FILES ${SRC_HDR})


IF(MSVC)
	SET(SRC_PCH ${SRC_DIR}/utils/pch.cpp)
	SOURCE_GROUP(src FILES ${SRC_PCH})
ENDIF()

INCLUDE_DIRECTORIES("${SRC_DIR}/utils")

ADD_LIBRARY(libutils STATIC ${INCLUDE} ${SRC} ${SRC_HDR} ${SRC_PCH})
SET_TARGET_PROPERTIES(libutils PROPERTIES PREFIX "" IMPORT_PREFIX "")

CREATE_PCH(libutils ${SRC_DIR}/utils/pch.hpp ${SRC_PCH})
USE_PCH(libutils ${SRC_DIR}/utils/pch.hpp ${SRC})

