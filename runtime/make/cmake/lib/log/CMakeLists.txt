PROJECT (log)


set (INCLUDE
	${INC_DIR}/log/client.hpp
)
SOURCE_GROUP(include FILES ${INCLUDE})

set (SRC
	${SRC_DIR}/heapNewDelete.cpp
	${SRC_DIR}/log/rootInitializer.cpp
)
SOURCE_GROUP(src FILES ${SRC})

#################################################
cmake_minimum_required (VERSION 2.6)
#set (CMAKE_VERBOSE_MAKEFILE on)

set (log4cplus_version_major 1)
set (log4cplus_version_minor 0)
set (log4cplus_version_patch 4)
set (log4cplus_soversion 4)

find_package (Threads REQUIRED)
#message (STATUS "Threads: ${CMAKE_THREAD_LIBS_INIT}")

set (INCLUDE_LOG4CPLUS
  ${INC_DIR}/log4cplus/appender.h
  ${INC_DIR}/log4cplus/config/macosx.h
  ${INC_DIR}/log4cplus/config/win32.h
  ${INC_DIR}/log4cplus/config.hxx
  ${INC_DIR}/log4cplus/configurator.h
  ${INC_DIR}/log4cplus/consoleappender.h
  ${INC_DIR}/log4cplus/fileappender.h
  ${INC_DIR}/log4cplus/fstreams.h
  ${INC_DIR}/log4cplus/helpers/appenderattachableimpl.h
  ${INC_DIR}/log4cplus/helpers/loglog.h
  ${INC_DIR}/log4cplus/helpers/logloguser.h
  ${INC_DIR}/log4cplus/helpers/pointer.h
  ${INC_DIR}/log4cplus/helpers/property.h
  ${INC_DIR}/log4cplus/helpers/sleep.h
  ${INC_DIR}/log4cplus/helpers/socket.h
  ${INC_DIR}/log4cplus/helpers/socketbuffer.h
  ${INC_DIR}/log4cplus/helpers/stringhelper.h
  ${INC_DIR}/log4cplus/helpers/syncprims.h
  ${INC_DIR}/log4cplus/helpers/thread-config.h
  ${INC_DIR}/log4cplus/helpers/threads.h
  ${INC_DIR}/log4cplus/helpers/timehelper.h
  ${INC_DIR}/log4cplus/hierarchy.h
  ${INC_DIR}/log4cplus/hierarchylocker.h
  ${INC_DIR}/log4cplus/layout.h
  ${INC_DIR}/log4cplus/logger.h
  ${INC_DIR}/log4cplus/loggingmacros.h
  ${INC_DIR}/log4cplus/loglevel.h
  ${INC_DIR}/log4cplus/ndc.h
  ${INC_DIR}/log4cplus/nteventlogappender.h
  ${INC_DIR}/log4cplus/nullappender.h
  ${INC_DIR}/log4cplus/socketappender.h
  ${INC_DIR}/log4cplus/spi/appenderattachable.h
  ${INC_DIR}/log4cplus/spi/factory.h
  ${INC_DIR}/log4cplus/spi/filter.h
  ${INC_DIR}/log4cplus/spi/loggerfactory.h
  ${INC_DIR}/log4cplus/spi/loggerimpl.h
  ${INC_DIR}/log4cplus/spi/loggingevent.h
  ${INC_DIR}/log4cplus/spi/objectregistry.h
  ${INC_DIR}/log4cplus/spi/rootlogger.h
  ${INC_DIR}/log4cplus/streams.h
  ${INC_DIR}/log4cplus/syslogappender.h
  ${INC_DIR}/log4cplus/tstring.h
  ${INC_DIR}/log4cplus/version.h
  ${INC_DIR}/log4cplus/win32debugappender.h
  ${INC_DIR}/log4cplus/win32consoleappender.h
)


set (SRC_LOG4CPLUS
  ${SRC_DIR}/log4cplus/appender.cxx
  ${SRC_DIR}/log4cplus/appenderattachableimpl.cxx
  ${SRC_DIR}/log4cplus/configurator.cxx
  ${SRC_DIR}/log4cplus/consoleappender.cxx
  ${SRC_DIR}/log4cplus/factory.cxx
  ${SRC_DIR}/log4cplus/fileappender.cxx
  ${SRC_DIR}/log4cplus/filter.cxx
  ${SRC_DIR}/log4cplus/global-init.cxx
  ${SRC_DIR}/log4cplus/hierarchy.cxx
  ${SRC_DIR}/log4cplus/hierarchylocker.cxx
  ${SRC_DIR}/log4cplus/layout.cxx
  ${SRC_DIR}/log4cplus/logger.cxx
  ${SRC_DIR}/log4cplus/loggerimpl.cxx
  ${SRC_DIR}/log4cplus/loggingevent.cxx
  ${SRC_DIR}/log4cplus/loglevel.cxx
  ${SRC_DIR}/log4cplus/loglog.cxx
  ${SRC_DIR}/log4cplus/logloguser.cxx
  ${SRC_DIR}/log4cplus/ndc.cxx
  ${SRC_DIR}/log4cplus/nullappender.cxx
  ${SRC_DIR}/log4cplus/objectregistry.cxx
  ${SRC_DIR}/log4cplus/patternlayout.cxx
  ${SRC_DIR}/log4cplus/pointer.cxx
  ${SRC_DIR}/log4cplus/property.cxx
  ${SRC_DIR}/log4cplus/rootlogger.cxx
  ${SRC_DIR}/log4cplus/sleep.cxx
  ${SRC_DIR}/log4cplus/socket.cxx
  ${SRC_DIR}/log4cplus/socketappender.cxx
  ${SRC_DIR}/log4cplus/socketbuffer.cxx
  ${SRC_DIR}/log4cplus/stringhelper.cxx
  ${SRC_DIR}/log4cplus/syncprims.cxx
  ${SRC_DIR}/log4cplus/syslogappender.cxx
  ${SRC_DIR}/log4cplus/threads.cxx
  ${SRC_DIR}/log4cplus/timehelper.cxx
  ${SRC_DIR}/log4cplus/version.cxx
)


if ("${UNIX}" OR "${CYGWIN}")
  set (SRC_LOG4CPLUS ${SRC_LOG4CPLUS}
    ${SRC_DIR}/log4cplus/socket-unix.cxx)
  set (INCLUDE_LOG4CPLUS ${INCLUDE_LOG4CPLUS}
    ${INC_DIR}/log4cplus/config/defines.hxx
    ${INC_DIR}/log4cplus/helpers/syncprims-pthreads.h)
elseif (WIN32)
  set (SRC_LOG4CPLUS ${SRC_LOG4CPLUS}
    ${SRC_DIR}/log4cplus/socket-win32.cxx
    ${SRC_DIR}/log4cplus/win32debugappender.cxx
    ${SRC_DIR}/log4cplus/nteventlogappender.cxx
    ${SRC_DIR}/log4cplus/win32consoleappender.cxx)
  set (INCLUDE_LOG4CPLUS ${INCLUDE_LOG4CPLUS}
    ${INC_DIR}/log4cplus/helpers/syncprims-win32.h)

endif ()

SOURCE_GROUP(log4cplus\\include FILES ${INCLUDE_LOG4CPLUS})
SOURCE_GROUP(log4cplus\\src FILES ${SRC_LOG4CPLUS})

ADD_DEFINITIONS(-DINSIDE_LOG4CPLUS)
ADD_DEFINITIONS(-Dlog4cplus_EXPORTS)


ADD_LIBRARY(liblog SHARED ${SRC_STUB} ${INCLUDE} ${SRC} ${INCLUDE_LOG4CPLUS} ${SRC_LOG4CPLUS})

SET_TARGET_PROPERTIES(liblog PROPERTIES 
	RUNTIME_OUTPUT_DIRECTORY ${SERVERBIN_DIR}
	LIBRARY_OUTPUT_DIRECTORY ${SERVERBIN_DIR})

target_link_libraries (liblog libheap ${CMAKE_THREAD_LIBS_INIT})

if (WIN32)
  target_link_libraries (liblog ws2_32 advapi32)
endif ()
