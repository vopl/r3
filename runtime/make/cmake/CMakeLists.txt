cmake_minimum_required(VERSION 2.6)
PROJECT(r3)

INCLUDE(Setup.cmake)
INCLUDE(Local.cmake)



#INCLUDE(CMakePrintSystemInformation)
#INCLUDE(CMakeExportBuildSettings)
#CMAKE_EXPORT_BUILD_SETTINGS(buildSettings.txt)

INCLUDE(excludeDefBuild.txt OPTIONAL)







################### boost

#SET(Boost_USE_STATIC_LIBS        ON)
SET(Boost_USE_MULTITHREADED      ON)
#SET(Boost_USE_STATIC_RUNTIME     ON)

FIND_PACKAGE( Boost 1.42.0 COMPONENTS date_time filesystem system thread serialization)
IF(NOT Boost_FOUND)
	MESSAGE(FATAL_ERROR "Boost 1.42.0 required")
ENDIF()
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
#LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})




ADD_SUBDIRECTORY(app)
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(plug)


