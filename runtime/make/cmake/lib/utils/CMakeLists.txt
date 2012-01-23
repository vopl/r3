PROJECT (libutils)

SET(INCLUDE
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

SET(SRC
	${SRC_DIR}/utils/base64.cpp
	${SRC_DIR}/utils/crc32.cpp
	${SRC_DIR}/utils/variant.cpp
	${SRC_DIR}/utils/variantLoad.cpp
	${SRC_DIR}/utils/variantLoadScope.cpp
	${SRC_DIR}/utils/variantLoadGrammar.cpp
	${SRC_DIR}/utils/variantSerialization.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_HDR
	${SRC_DIR}/utils/variantDumper.hpp
	${SRC_DIR}/utils/variantImpl.hpp
	${SRC_DIR}/utils/variantLoadScope.hpp
	${SRC_DIR}/utils/variantLoadGrammar.hpp
	${SRC_DIR}/utils/variantConvertMatrix.hpp
	${SRC_DIR}/utils/pch.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})


SET(SRC_PCH
	${SRC_DIR}/utils/pch.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})

INCLUDE_DIRECTORIES("${SRC_DIR}/utils")

ADD_LIBRARY(libutils STATIC ${SRC_STUB} ${INCLUDE} ${SRC} ${SRC_HDR} ${SRC_PCH})

CREATE_PCH(libutils ${SRC_DIR}/utils/pch.h ${SRC_PCH})
USE_PCH(libutils ${SRC_DIR}/utils/pch.h ${SRC})

