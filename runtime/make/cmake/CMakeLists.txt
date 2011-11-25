cmake_minimum_required(VERSION 2.8)
PROJECT(r3)

INCLUDE(Setup.cmake)
#SET(CMAKE_SHARED_LIBRARY_PREFIX ../../bin/)


ADD_SUBDIRECTORY(apps)
ADD_SUBDIRECTORY(libs)
ADD_SUBDIRECTORY(plugs)

#INCLUDE(CMakePrintSystemInformation)
#INCLUDE(CMakeExportBuildSettings)
#CMAKE_EXPORT_BUILD_SETTINGS(buildSettings.txt)

INCLUDE(excludeDefBuild.txt OPTIONAL)


