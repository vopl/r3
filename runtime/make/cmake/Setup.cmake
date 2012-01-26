SET(CMAKE_USE_RELATIVE_PATHS TRUE)
#SET(CMAKE_SKIP_RPATH "TRUE")


IF(COMMAND cmake_policy)
	CMAKE_POLICY(SET CMP0003 NEW)
ENDIF(COMMAND cmake_policy)



INCLUDE(Local.cmake OPTIONAL)

SET(INSTALL_PDB 0)












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
 	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ot /Og /Oi /Ox /GL /Zi")
 	SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /LTCG /DEBUG")
 	SET(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS_RELEASE} /LTCG /DEBUG")
 	SET(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /LTCG /DEBUG")
ENDIF(MSVC)



#######################################################################################
#IF(CMAKE_COMPILER_IS_GNUCXX AND NOT WIN32)
#	#need for correct resolving symbols with dlsym
#	SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -symbolic")
#ENDIF(CMAKE_COMPILER_IS_GNUCXX AND NOT WIN32)


#######################################################################################
IF(CMAKE_COMPILER_IS_GNUCXX AND NOT WINDOWS)
	#need for correct resolving symbols with dlsym
	SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -fPIC)
	SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -fpermissive)
ENDIF(CMAKE_COMPILER_IS_GNUCXX AND NOT WINDOWS)



#######################################################################################
IF(CMAKE_COMPILER_IS_GNUCXX)
 	SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Xlinker --no-undefined")
 	SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Xlinker --no-undefined")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)



STRING(TOUPPER "${CMAKE_BUILD_TYPE}" BUILD_TYPE_UC)







#######################################################################################
INCLUDE(Pch.cmake)

#######################################################################################
INCLUDE(Logging.cmake)

#######################################################################################
INCLUDE(SetupBinOut.cmake)




#######################################################################################
IF(SOLARIS)
    SET(CMAKE_CXX_CREATE_SHARED_LIBRARY
        "<CMAKE_CXX_COMPILER> <CMAKE_SHARED_LIBRARY_CXX_FLAGS> <LINK_FLAGS> <CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS>  <CMAKE_SHARED_LIBRARY_SONAME_CXX_FLAG><TARGET_SONAME> -o <TARGET> <OBJECTS> <LINK_LIBRARIES>")
ENDIF(SOLARIS)



#######################################################################################
SET(CMAKE_INSTALL_PREFIX ${ROOT_DIR})
