IF(CMAKE_SIZEOF_VOID_P MATCHES "8")
	SET(X64 on)
ELSE()
	SET(X64 off)
ENDIF()


IF(WINDOWS)
	SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "p:/sdk/boost_1_48_0")

	IF(X64)
		SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "P:/sdk/boost_1_48_0/stage/lib.x64")
	ELSE()
		SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "P:/sdk/boost_1_48_0/stage/lib.x86")
	ENDIF()

	SET(Boost_ADDITIONAL_VERSIONS "1.48.0")



	IF(X64)
		SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "p:/sdk/OpenSSL-Win64-1.0.0.e/include")
		SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "P:/sdk/OpenSSL-Win64-1.0.0.e/lib/VC/")
	ELSE()
		SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "p:/sdk/OpenSSL-Win32-1.0.0.e/include")
		SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "P:/sdk/OpenSSL-Win32-1.0.0.e/lib/mingw/")
	ENDIF()

	IF(X64)
		SET(ENV{PostgreSQL_ROOT} "C:/Program Files/PostgreSQL/9.1")
	ELSE()
		SET(ENV{PostgreSQL_ROOT} "C:/Program Files (x86)/PostgreSQL/9.1")
	ENDIF()


	IF(X64)
		SET(QT_QMAKE_EXECUTABLE "P:/sdk/qt/x64/4.8.0/bin/qmake.exe")
	ELSE()
		SET(QT_QMAKE_EXECUTABLE "C:/QtSDK/Desktop/Qt/4.7.4/mingw/bin/qmake.exe")
	ENDIF()

ENDIF()
