SET(CMAKE_BUILD_TYPE "Debug")
#SET(CMAKE_BUILD_TYPE "RelWithDebInfo")
SET(CMAKE_VERBOSE_MAKEFILE "on")
SET(CMAKE_USE_RELATIVE_PATH "TRUE")
#SET(CMAKE_SKIP_RPATH "TRUE")


IF(COMMAND cmake_policy)
	CMAKE_POLICY(SET CMP0003 NEW)
ENDIF(COMMAND cmake_policy)



SET(INSTALL_PDB 0)








#логирование количества ссылок на msoi объекты
#ADD_DEFINITIONS(-DADDREFRELEASE_DO_LOG)

#логирование _new _delete
#ADD_DEFINITIONS(-DNEWDELETE_DO_LOG)

#использовать сенсоры метрик
#ADD_DEFINITIONS(-DUSE_METRICS)











#######################################################################################
SET(ROOT_DIR ${CMAKE_SOURCE_DIR}/../..)
GET_FILENAME_COMPONENT(ROOT_DIR ${ROOT_DIR} ABSOLUTE)
SET(SRC_DIR ${ROOT_DIR}/src)
SET(INC_DIR ${ROOT_DIR}/include)
SET(DOC_DIR ${ROOT_DIR}/doc)
SET(LIB_DIR ${ROOT_DIR}/lib)
SET(PLUG_DIR ${ROOT_DIR}/plug)

SET(SERVERBIN_DIR ${ROOT_DIR}/server)
SET(CLIENTBIN_DIR ${ROOT_DIR}/client)




#######################################################################################
#SET(PROJECT_GROUP "NESTED-1")




#######################################################################################
IF(CMAKE_SYSTEM MATCHES "Windows*")
	SET(WINDOWS 1)
	ADD_DEFINITIONS(-DOS_WINDOWS)
ENDIF(CMAKE_SYSTEM MATCHES "Windows*")
IF(CMAKE_SYSTEM MATCHES "SunOS*")
	SET(SOLARIS 1)
	ADD_DEFINITIONS(-DOS_SOLARIS)
ENDIF(CMAKE_SYSTEM MATCHES "SunOS*")
IF(CMAKE_SYSTEM MATCHES "FreeBSD*")
	SET(FREEBSD 1)
	ADD_DEFINITIONS(-DOS_FREEBSD)
ENDIF(CMAKE_SYSTEM MATCHES "FreeBSD*")
IF(CMAKE_SYSTEM MATCHES "Linux*")
	SET(LINUX 1)
	ADD_DEFINITIONS(-DOS_LINUX)
ENDIF(CMAKE_SYSTEM MATCHES "Linux*")

IF(WINDOWS OR SOLARIS OR FREEBSD OR LINUX)
	MESSAGE(STATUS "System in use: ${CMAKE_SYSTEM}")
ELSE(WINDOWS OR SOLARIS OR FREEBSD)
	MESSAGE(SEND_ERROR "WARNING!!! Unknown system: ${CMAKE_SYSTEM}")
ENDIF(WINDOWS OR SOLARIS OR FREEBSD OR LINUX)




IF(NOT WINDOWS)
	#для watch окна msvc симулировать тип KDataNode для удобного наблюдения
	#FIND_PROGRAM(gcc_cpp NAMES "g++44" "g++42" "g++")
	#FIND_PROGRAM(gcc_c NAMES "gcc44" "gcc42" "gcc")


	#IF(NOT "${gcc_cpp}" STREQUAL "gcc_cpp-NOTFOUND")
	#	MESSAGE("-- cxx compiler: ${gcc_cpp}")
	#	MESSAGE("-- c compiler: ${gcc_c}")
	
	#	SET(CMAKE_CXX_COMPILER ${gcc_cpp})
	#	SET(CMAKE_C_COMPILER ${gcc_c})
	#ENDIF(NOT "${gcc_cpp}" STREQUAL "gcc_cpp-NOTFOUND")
ENDIF(NOT WINDOWS)

#######################################################################################
IF(WINDOWS)
	ADD_DEFINITIONS(-D_WIN32_WINNT=0x0501)
ENDIF(WINDOWS)





#######################################################################################
IF(MSVC)
	ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE)
	ADD_DEFINITIONS(-D_SCL_SECURE_NO_DEPRECATE)
	ADD_DEFINITIONS(-D_CRT_NONSTDC_NO_DEPRECATE)
	#ADD_DEFINITIONS(-D_HAS_ITERATOR_DEBUGGING=0)
ENDIF(MSVC)





#######################################################################################
INCLUDE_DIRECTORIES(../../include)






#######################################################################################
IF(MSVC)
	#chose runtime library to multithreaded static
	#SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
 	#SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
 	#SET(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /MT")
 	#SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /MT")
ENDIF(MSVC)


IF(MSVC)
 	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ot /Og /Oi /Ox /GL /Zi")
 	SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /LTCG /DEBUG")
 	SET(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS_RELEASE} /LTCG /DEBUG")
 	SET(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /LTCG /DEBUG")
ENDIF(MSVC)



#SET_PROPERTY(DIRECTORY "." PROPERTY COMPILE_DEFINITIONS_DEBUG "${COMPILE_DEFINITIONS_DEBUG}")
#SET_PROPERTY(DIRECTORY "." PROPERTY COMPILE_DEFINITIONS_RELWITHDEBINFO "${COMPILE_DEFINITIONS_RELWITHDEBINFO};LOG4CPLUS_DISABLE_DEBUG")
#SET_PROPERTY(DIRECTORY "." PROPERTY COMPILE_DEFINITIONS_MINSIZEREL "${COMPILE_DEFINITIONS_MINSIZEREL};LOG4CPLUS_DISABLE_INFO")
#SET_PROPERTY(DIRECTORY "." PROPERTY COMPILE_DEFINITIONS_RELEASE "${COMPILE_DEFINITIONS_RELEASE};LOG4CPLUS_DISABLE_INFO")




#######################################################################################
#IF(CMAKE_COMPILER_IS_GNUCXX AND NOT WIN32)
#	#need for correct resolving symbols with dlsym
#	SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -symbolic")
#ENDIF(CMAKE_COMPILER_IS_GNUCXX AND NOT WIN32)


#######################################################################################
IF(CMAKE_COMPILER_IS_GNUCXX AND NOT WINDOWS)
	#need for correct resolving symbols with dlsym
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
ENDIF(CMAKE_COMPILER_IS_GNUCXX AND NOT WINDOWS)



#######################################################################################
IF(CMAKE_COMPILER_IS_GNUCXX)
 	SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Xlinker --no-undefined")
 	SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Xlinker --no-undefined")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)


IF(CMAKE_COMPILER_IS_GNUCXX)
	#SET(CMAKE_SHARED_LIBRARY_PREFIX "")
	#SET(CMAKE_IMPORT_LIBRARY_PREFIX "")
	#SET(CMAKE_STATIC_LIBRARY_PREFIX "")
	#SET(CMAKE_SHARED_MODULE_PREFIX "")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)


STRING(TOUPPER "${CMAKE_BUILD_TYPE}" BUILD_TYPE_UC)









#######################################################################################
MACRO(TO_NATIVE_PATH PATH OUT)
	FILE(TO_NATIVE_PATH "${PATH}" "${OUT}")
	IF(MINGW)
		STRING(REPLACE "/" "\\" "${OUT}" "${${OUT}}")
	ENDIF(MINGW)
ENDMACRO(TO_NATIVE_PATH)

#######################################################################################
IF(MSVC)
	MACRO(PCH_KEY2FILENAME pchfile key header)
		GET_FILENAME_COMPONENT(filename ${header} NAME_WE)
		SET(pchfile "$(IntDir)/${filename}.pch")
		GET_FILENAME_COMPONENT(key ${header} NAME)
	ENDMACRO(PCH_KEY2FILENAME)


	MACRO(CREATE_PCH target header srcfile)
		PCH_KEY2FILENAME(pchfile key ${header})

		SET_SOURCE_FILES_PROPERTIES(${srcfile} PROPERTIES COMPILE_FLAGS "/Yc${key} /Fp${pchfile}")
#		MESSAGE("precompiled ${key} created by ${srcfile}")
	ENDMACRO(CREATE_PCH)

	MACRO(USE_PCH target header)
		PCH_KEY2FILENAME(pchfile key ${header})
	
		FOREACH(i ${ARGN})
			SET_SOURCE_FILES_PROPERTIES(${i} PROPERTIES COMPILE_FLAGS "/Yu${key} /Fp${pchfile}")
#			MESSAGE("precompiled ${key} used in ${i}")
		ENDFOREACH(i)
	ENDMACRO(USE_PCH)
ELSE(MSVC)





	MACRO(PCH_KEY2FILENAME pchfile key header)
		GET_FILENAME_COMPONENT(filename ${header} NAME)
		GET_FILENAME_COMPONENT(path ${header} PATH)
		#SET(path ${CMAKE_CURRENT_BINARY_DIR})
		SET(pchfile "${path}/${filename}.gch")

		#GET_FILENAME_COMPONENT(key ${header} NAME)
	ENDMACRO(PCH_KEY2FILENAME)






	MACRO(CREATE_PCH target header srcfile)
	
		PCH_KEY2FILENAME(pchfile key ${header})
		GET_FILENAME_COMPONENT(pchfile_path ${pchfile} PATH)
		
		GET_DIRECTORY_PROPERTY(INCS INCLUDE_DIRECTORIES)
		SET(IINCS)
		FOREACH(i ${INCS})
			LIST(APPEND IINCS "-I" ${i})
		ENDFOREACH(i)

		GET_DIRECTORY_PROPERTY(DEFS DEFINITIONS)

		TO_NATIVE_PATH("${CMAKE_CXX_COMPILER}" cxx_compiler)
		#FILE(TO_NATIVE_PATH "${CMAKE_CXX_COMPILER}" cxx_compiler)
		#MESSAGE("${cxx_compiler}")

		SET(cxx_args ${DEFS} ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_${BUILD_TYPE_UC}} ${IINCS} ${header} -o ${pchfile})
		SEPARATE_ARGUMENTS(cxx_args)

		SET(target_pch ${target}_build_pch)

		ADD_CUSTOM_COMMAND(OUTPUT ${pchfile} 
			COMMAND ${cxx_compiler} ${cxx_args}
			DEPENDS ${header})

		#SET(CMAKE_CXX_FLAGS_${BUILD_TYPE_UC} "-I${pchfile_path} ${CMAKE_CXX_FLAGS_${BUILD_TYPE_UC}}")

#		MESSAGE("precompiled ${key} created by ${srcfile}")
	ENDMACRO(CREATE_PCH)

	MACRO(USE_PCH target header)
		PCH_KEY2FILENAME(pchfile key ${header})
		GET_FILENAME_COMPONENT(pchfile_path ${pchfile} PATH)

		FOREACH(i ${ARGN})
			SET_SOURCE_FILES_PROPERTIES(${i} PROPERTIES COMPILE_FLAGS "-Winvalid-pch -include ${header}" )
			SET_SOURCE_FILES_PROPERTIES(${i} PROPERTIES OBJECT_DEPENDS ${pchfile} )
#			MESSAGE("precompiled ${key} used in ${i}")
		ENDFOREACH(i)
	ENDMACRO(USE_PCH)
	
	
	
	
	
	
	
	
ENDIF(MSVC)


#######################################################################################
# SETUP_BIN_OUT

MACRO(SETUP_BIN_OUT target dst)

	GET_TARGET_PROPERTY(TARGET_LOCATION ${target} "LOCATION")

	IF("${ARGV2}" STREQUAL "")
		GET_FILENAME_COMPONENT(TARGET_NAME ${TARGET_LOCATION} NAME_WE)
	ENDIF()

	IF(NOT "${ARGV2}" STREQUAL "")
		SET(TARGET_NAME ${ARGV2})
	ENDIF()

	GET_TARGET_PROPERTY(TARGET_LOCATION ${target} "LOCATION")
	GET_FILENAME_COMPONENT(TARGET_EXT ${TARGET_LOCATION} EXT)

	FILE(TO_NATIVE_PATH ${TARGET_LOCATION} FROM)
	FILE(TO_NATIVE_PATH "${ROOT_DIR}/${dst}/${TARGET_NAME}${TARGET_EXT}" TO)

	ADD_CUSTOM_COMMAND(
		TARGET ${target}
		POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy "${FROM}" "${TO}")

	#ADD_CUSTOM_TARGET(
	#	"${target}_${dst}_${TARGET_NAME}"
	#	${CMAKE_COMMAND} -E copy "${FROM}" "${TO}"
	#	DEPENDS ${target})
ENDMACRO()





#######################################################################################
IF(WINDOWS)
	#SET(libboost_suffix "")
ELSE(WINDOWS)
    IF(SOLARIS)
	#SET(libboost_suffix "-gcc34")
    ENDIF(SOLARIS)
ENDIF(WINDOWS)


IF(SOLARIS)
    SET(CMAKE_CXX_CREATE_SHARED_LIBRARY
        "<CMAKE_CXX_COMPILER> <CMAKE_SHARED_LIBRARY_CXX_FLAGS> <LINK_FLAGS> <CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS>  <CMAKE_SHARED_LIBRARY_SONAME_CXX_FLAG><TARGET_SONAME> -o <TARGET> <OBJECTS> <LINK_LIBRARIES>")
ENDIF(SOLARIS)



#######################################################################################
SET(CMAKE_INSTALL_PREFIX ${ROOT_DIR})
