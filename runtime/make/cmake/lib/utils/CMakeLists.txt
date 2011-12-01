PROJECT (libutils)

SET(INCLUDE
	${INC_DIR}/utils/aton.hpp
	${INC_DIR}/utils/base64.h
	${INC_DIR}/utils/crc32.hpp
	${INC_DIR}/utils/dateTimeDuration.hpp
	${INC_DIR}/utils/fixEndian.hpp
	${INC_DIR}/utils/implAccess.hpp
	${INC_DIR}/utils/julian.h
	${INC_DIR}/utils/ntoa.hpp
	${INC_DIR}/utils/serialization.hpp
	${INC_DIR}/utils/streambufOnArray.hpp
	${INC_DIR}/utils/variant.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

SET(INCLUDE_SERIALIZATION
	${INC_DIR}/utils/serialization/binary_portable_iarchive.hpp
	${INC_DIR}/utils/serialization/binary_portable_iarchive_impl.hpp
	${INC_DIR}/utils/serialization/binary_portable_oarchive.hpp
	${INC_DIR}/utils/serialization/binary_portable_oarchive_impl.hpp
	${INC_DIR}/utils/serialization/collection_size_type.hpp
	${INC_DIR}/utils/serialization/polymorphic_binary_portable_iarchive.hpp
	${INC_DIR}/utils/serialization/polymorphic_binary_portable_oarchive.hpp
)
SOURCE_GROUP(include\\serialization FILES ${INCLUDE_SERIALIZATION})

SET(SRC
	${SRC_DIR}/utils/base64.cpp
	${SRC_DIR}/utils/crc32.cpp
	${SRC_DIR}/utils/variant.cpp
)
SOURCE_GROUP(src FILES ${SRC})

SET(SRC_HDR
	${SRC_DIR}/utils/variantDumper.hpp
	${SRC_DIR}/utils/variantImpl.hpp
	${SRC_DIR}/utils/pch.h
)
SOURCE_GROUP(src FILES ${SRC_HDR})

SET(SRC_SERIALIZATION
	${SRC_DIR}/utils/serialization/binary_portable_iarchive.cpp
	${SRC_DIR}/utils/serialization/binary_portable_oarchive.cpp
)
SOURCE_GROUP(src\\serialization FILES ${SRC_SERIALIZATION})


SET(SRC_PCH
	${SRC_DIR}/utils/pch.cpp
)
SOURCE_GROUP(src FILES ${SRC_PCH})

INCLUDE_DIRECTORIES("${SRC_DIR}/utils")

PRESETUP_BIN_OUT(SRC_STUB)
ADD_LIBRARY(libutils STATIC ${SRC_STUB} ${INCLUDE} ${INCLUDE_SERIALIZATION} ${SRC} ${SRC_HDR} ${SRC_SERIALIZATION} ${SRC_PCH})

CREATE_PCH(libutils ${SRC_DIR}/utils/pch.h ${SRC_PCH})
USE_PCH(libutils ${SRC_DIR}/utils/pch.h ${SRC})
USE_PCH(libutils ${SRC_DIR}/utils/pch.h ${SRC_SERIALIZATION})

SETUP_BIN_OUT(libutils lib)

