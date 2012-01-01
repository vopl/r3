cmake_minimum_required(VERSION 2.6)
if(POLICY CMP0011)
    # Included scripts do automatic cmake_policy PUSH and POP.
    cmake_policy(SET CMP0011 OLD)
endif(POLICY CMP0011)

PROJECT(r3)

INCLUDE(Setup.cmake)
INCLUDE(Local.cmake)



#INCLUDE(CMakePrintSystemInformation)
#INCLUDE(CMakeExportBuildSettings)
#CMAKE_EXPORT_BUILD_SETTINGS(buildSettings.txt)








################### boost

SET(Boost_USE_STATIC_LIBS        OFF)
SET(Boost_USE_MULTITHREADED      ON)
SET(Boost_USE_STATIC_RUNTIME     OFF)

FIND_PACKAGE( Boost 1.42.0 COMPONENTS date_time filesystem system thread)
IF(NOT Boost_FOUND)
	MESSAGE(FATAL_ERROR "Boost 1.42.0 required")
ENDIF()
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
#LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

IF(WIN32)
	ADD_DEFINITIONS(-DBOOST_ALL_DYN_LINK)
	#ADD_DEFINITIONS(-DBOOST_LIB_DIAGNOSTIC)
ENDIF(WIN32)



ADD_SUBDIRECTORY(app)
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(plug)


INCLUDE(excludeDefBuild.txt OPTIONAL)
