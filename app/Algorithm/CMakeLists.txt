# This is a CMake build file, for more information consult:
# http://en.wikipedia.org/wiki/CMake
# and
# http://www.cmake.org/Wiki/CMake
# http://www.cmake.org/cmake/help/syntax.html
# http://www.cmake.org/Wiki/CMake_Useful_Variables
# http://www.cmake.org/cmake/help/cmake-2-8-docs.html

# to compile the local code you can use: cmake ./ && make -j2

# ----------------------------------------------------------------------
# Base CMake setup
CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
FIND_PACKAGE (OpenCV 2.4 REQUIRED)

#-----------------   common setting -------------------
SET(ROOT_DIR ../)
SET(EXECUTABLE_OUTPUT_PATH ${ROOT_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(
	./
	/usr/include/eigen2
	${local_INCLUDE_DIRS_ALL}
)

#MESSAGE(STATUS "CMAKE_CURRENT_BINARY_DIR " ${CMAKE_CURRENT_BINARY_DIR})

#-------------------------- add common files 	-------------------------
FILE(GLOB src_main
    "./*.cpp"
    "./GraphUtils/*.cpp"
    )

FILE(GLOB h_main
    "./*.h"
    )
    
#MESSAGE(STATUS "CPP: " ${src_main})
#MESSAGE(STATUS "H: " ${h_qt})

#----------------- UNIX and WINDOWS difference -------------

SET(opencv_LIBRARIES
    opencv_core opencv_imgproc opencv_highgui opencv_ml
    opencv_video opencv_features2d
    opencv_calib3d
    opencv_objdetect opencv_contrib
    opencv_legacy opencv_flann
   ) # quick hack for opencv2.4 support

#------------------ build application -----------
SET(appname main)

ADD_EXECUTABLE(${appname} ${src_main} ${h_moc} ${headers_ui} ${h_main}

)
#MESSAGE(STATUS "ui: " ${headers_ui})
#MESSAGE(STATUS "qt: " ${QT_LIBRARIES})
TARGET_LINK_LIBRARIES( 
	${appname}
        ${boost_LIBRARIES}
        ${opencv_LIBRARIES}
        )

