#SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_BUILD_TYPE "RelWithDebInfo")
#SET(CMAKE_VERBOSE_MAKEFILE "on")
#SET(CMAKE_USE_RELATIVE_PATH "TRUE")
SET(CMAKE_SKIP_RPATH "TRUE")
SET(COPY_BIN_OUT 1)


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
SET(BIN_DIR ${ROOT_DIR}/bin)
SET(LIB_DIR ${ROOT_DIR}/lib)
SET(PLUG_DIR ${ROOT_DIR}/plug)




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
IF(MSVC)
	ADD_DEFINITIONS(-D_WIN32_WINNT=0x0501)
ENDIF(MSVC)





#######################################################################################
IF(MSVC)
	ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE)
	ADD_DEFINITIONS(-D_SCL_SECURE_NO_DEPRECATE)
	ADD_DEFINITIONS(-D_CRT_NONSTDC_NO_DEPRECATE)
	#ADD_DEFINITIONS(-D_HAS_ITERATOR_DEBUGGING=0)
ENDIF(MSVC)





#######################################################################################
INCLUDE_DIRECTORIES(../../include)

IF(WIN32)
#	INCLUDE_DIRECTORIES(P:/sdk/boost_1_33_1/)
#	LINK_DIRECTORIES(P:/sdk/boost_1_33_1/bin/)
# 
#	INCLUDE_DIRECTORIES(P:/sdk/iconv/include/)
#	LINK_DIRECTORIES(P:/sdk/iconv/lib/)
#
#	INCLUDE_DIRECTORIES(P:/sdk/apache_1.3.33/src/include/)
#	INCLUDE_DIRECTORIES(P:/sdk/apache_1.3.33/src/os/win32/)
#	LINK_DIRECTORIES(P:/sdk/apache_1.3.33/libexec/)
#
#	INCLUDE_DIRECTORIES("C:/Program Files/PostgreSQL/8.0/include/")
#	LINK_DIRECTORIES("C:/Program Files/PostgreSQL/8.0/lib/ms")
#
#	INCLUDE_DIRECTORIES(P:/sdk/php-5.2.4/)
#	INCLUDE_DIRECTORIES(P:/sdk/php-5.2.4/TSRM/)
#	INCLUDE_DIRECTORIES(P:/sdk/php-5.2.4/regex/)
#	INCLUDE_DIRECTORIES(P:/sdk/php-5.2.4/main/)
#	INCLUDE_DIRECTORIES(P:/sdk/php-5.2.4/Zend/)
#	LINK_DIRECTORIES(P:/sdk/php-5.2.4/bin/dev/)
ENDIF(WIN32)

IF(NOT WIN32)
#	INCLUDE_DIRECTORIES(/usr/local/include)
#	LINK_DIRECTORIES(/usr/local/lib)
#	INCLUDE_DIRECTORIES(/usr/include)
#	LINK_DIRECTORIES(/usr/lib)
ENDIF(NOT WIN32)





#######################################################################################
IF(MSVC)
	#chose runtime library to multithreaded static
	SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
 	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
 	SET(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /MT")
 	SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /MT")
ENDIF(MSVC)


IF(MSVC)
 	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ot /Og /Oi /Ox /GL")
 	SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /LTCG")
 	SET(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS_RELEASE} /LTCG")
 	SET(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /LTCG")
ENDIF(MSVC)



SET_PROPERTY(DIRECTORY "." PROPERTY COMPILE_DEFINITIONS_DEBUG "${COMPILE_DEFINITIONS_DEBUG}")
SET_PROPERTY(DIRECTORY "." PROPERTY COMPILE_DEFINITIONS_RELWITHDEBINFO "${COMPILE_DEFINITIONS_RELWITHDEBINFO};LOG4CPLUS_DISABLE_DEBUG")
SET_PROPERTY(DIRECTORY "." PROPERTY COMPILE_DEFINITIONS_MINSIZEREL "${COMPILE_DEFINITIONS_MINSIZEREL};LOG4CPLUS_DISABLE_INFO")
SET_PROPERTY(DIRECTORY "." PROPERTY COMPILE_DEFINITIONS_RELEASE "${COMPILE_DEFINITIONS_RELEASE};LOG4CPLUS_DISABLE_INFO")




#######################################################################################
#IF(CMAKE_COMPILER_IS_GNUCXX AND NOT WIN32)
#	#need for correct resolving symbols with dlsym
#	SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -symbolic")
#ENDIF(CMAKE_COMPILER_IS_GNUCXX AND NOT WIN32)


#######################################################################################
IF(CMAKE_COMPILER_IS_GNUCXX)
	#need for correct resolving symbols with dlsym
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)



#######################################################################################
IF(CMAKE_COMPILER_IS_GNUCXX)
 	SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Xlinker --no-undefined")
 	SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Xlinker --no-undefined")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)



STRING(TOUPPER "${CMAKE_BUILD_TYPE}" BUILD_TYPE_UC)

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
		GET_FILENAME_COMPONENT(filename ${header} NAME_WE)
		GET_FILENAME_COMPONENT(path ${header} PATH)
		SET(pchfile "${path}/${filename}.h.gch")

		GET_FILENAME_COMPONENT(key ${header} NAME)
	ENDMACRO(PCH_KEY2FILENAME)






	MACRO(CREATE_PCH target header srcfile)
	
		PCH_KEY2FILENAME(pchfile key ${header})
		
		GET_DIRECTORY_PROPERTY(INCS INCLUDE_DIRECTORIES)
		SET(IINCS "")
		FOREACH(i ${INCS})
			SET(IINCS "${IINCS} -I${i}")
		ENDFOREACH(i)

		GET_DIRECTORY_PROPERTY(DEFS DEFINITIONS)

		SET(PCH_BUILD_COMMAND "${CMAKE_CXX_COMPILER} ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_${BUILD_TYPE_UC}} ${IINCS} ${DEFS} ${header}")
		
		SET(target_pch ${target}_build_pch)

		ADD_CUSTOM_COMMAND(OUTPUT ${pchfile} COMMAND sh -c "${PCH_BUILD_COMMAND}" DEPENDS ${header})

		SET_SOURCE_FILES_PROPERTIES(${srcfile} PROPERTIES COMPILE_FLAGS "-include ${header} -Winvalid-pch -fPIC" )
		SET_SOURCE_FILES_PROPERTIES(${srcfile} PROPERTIES OBJECT_DEPENDS ${pchfile} )
	ENDMACRO(CREATE_PCH)

	MACRO(USE_PCH target header srcfile)
		PCH_KEY2FILENAME(pchfile key ${header})
		
		SET_SOURCE_FILES_PROPERTIES(${srcfile} PROPERTIES COMPILE_FLAGS "-include ${header} -Winvalid-pch -fPIC" )
		SET_SOURCE_FILES_PROPERTIES(${srcfile} PROPERTIES OBJECT_DEPENDS ${pchfile} )
	ENDMACRO(USE_PCH)
	
	
	
	
	
	
	
	
ENDIF(MSVC)





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




IF(MSVC AND COPY_BIN_OUT)
	MACRO(PRESETUP_BIN_OUT src)
		SET(${src} "${CMAKE_CURRENT_BINARY_DIR}/$(ConfigurationName)/stub4out")
		SET_SOURCE_FILES_PROPERTIES($${src}} PROPERTIES GENERATED true SYMBOLIC true)
	ENDMACRO(PRESETUP_BIN_OUT)

	MACRO(SETUP_BIN_OUT_RENAME target folder newname)

		SET(STUB4OUT "${CMAKE_CURRENT_BINARY_DIR}/$(ConfigurationName)/stub4out")

		GET_DIRECTORY_PROPERTY(PDIR PARENT_DIRECTORY)
		STRING(REPLACE "${CMAKE_SOURCE_DIR}/" "" PLDIR ${PDIR})
		SET_TARGET_PROPERTIES(${target} PROPERTIES PROJECT_LABEL "${PLDIR}/${target}")

		GET_TARGET_PROPERTY(TARGET_LOCATION ${target} "LOCATION")
		GET_FILENAME_COMPONENT(TARGET_EXT ${TARGET_LOCATION} EXT)

		FILE(TO_NATIVE_PATH ${TARGET_LOCATION} FROM)
		FILE(TO_NATIVE_PATH "${ROOT_DIR}/${folder}/${newname}${TARGET_EXT}" TO)

		ADD_CUSTOM_COMMAND(
			OUTPUT ${STUB4OUT} 
			COMMAND echo copy nul \"${STUB4OUT}\" 
			COMMAND copy nul \"${STUB4OUT}\" 
			DEPENDS ${FROM} ${TO}
		)

		ADD_CUSTOM_COMMAND(
			TARGET ${target} 
			POST_BUILD 
			COMMAND echo copy \"${FROM}\" \"${TO}\" 
			COMMAND copy \"${FROM}\" \"${TO}\"
		)
	ENDMACRO(SETUP_BIN_OUT_RENAME)

	MACRO(SETUP_BIN_OUT target folder)
		GET_TARGET_PROPERTY(TARGET_LOCATION ${target} "LOCATION")
		GET_FILENAME_COMPONENT(TARGET_NAME ${TARGET_LOCATION} NAME_WE)
		SETUP_BIN_OUT_RENAME(${target} ${folder} ${TARGET_NAME})
	ENDMACRO(SETUP_BIN_OUT)
	
ELSE(MSVC AND COPY_BIN_OUT)
	MACRO(PRESETUP_BIN_OUT src)
	ENDMACRO(PRESETUP_BIN_OUT)
	MACRO(SETUP_BIN_OUT target)
	ENDMACRO(SETUP_BIN_OUT)
ENDIF(MSVC AND COPY_BIN_OUT)


