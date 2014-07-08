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
cmake_minimum_required (VERSION 2.8)
find_package(OpenCV 2.4 REQUIRED)

#-----------------   common setting -------------------
SET(ROOT_DIR ../../)
SET(EXECUTABLE_OUTPUT_PATH ${ROOT_DIR})
option(FLY_CAMERA "Should the point gray camera be used ?" FALSE)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES("./")

MESSAGE(STATUS "CMAKE_CURRENT_BINARY_DIR " ${CMAKE_CURRENT_BINARY_DIR})

#-------------------------- add common files 	-------------------------
SET(src_main
    "main.cpp"
    "widget_demo.cpp"
    "demo_interface.cpp")

file(GLOB h_main
    "*.hpp")
set(h_qt "widget_demo.h")


MESSAGE(STATUS "CPP: " ${src_main})
MESSAGE(STATUS "H: " ${h_qt})


add_subdirectory(ex_code)
add_subdirectory(background_cut)
add_subdirectory(visual_features)
add_subdirectory(multi_tracker)
add_subdirectory(saliency_cut)
add_subdirectory(tricky_part)

#-----------------  set QT4 files ---------------
FIND_PACKAGE(Qt REQUIRED)
MESSAGE(STATUS "QT_USE_FILE" ${QT_USE_FILE}) # include qt cmake files
INCLUDE(${QT_USE_FILE}
SET(src_forms widget_demo.ui)

QT4_WRAP_UI(headers_ui ${src_forms})
QT4_WRAP_CPP(h_moc ${h_qt})

#----------------- UNIX and WINDOWS difference -------------

set(QT_ROOT "/usr/share/qt4")
set(opencv_LIBRARIES
    opencv_core opencv_imgproc opencv_highgui opencv_ml
    opencv_video opencv_features2d
    opencv_calib3d
    opencv_objdetect opencv_contrib
    opencv_legacy opencv_flann
   ) # quick hack for opencv2.4 support

#------------------ build application -----------
SET(appname main)

ADD_EXECUTABLE(${appname} ${src_main} ${h_moc} ${headers_ui} ${h_main})
MESSAGE(STATUS "ui: " ${headers_ui})
ADD_EXECUTABLE(${test_app_name} widget_demo.cpp demo_interface.cpp ${test_main} ${h_moc} ${headers_ui} ${h_main})

MESSAGE(STATUS "qt: " ${QT_LIBRARIES})
TARGET_LINK_LIBRARIES( ${appname}
		${QT_QTMAIN_LIBRARY} 
        ${QT_LIBRARIES}
        ${boost_LIBRARIES}
        ${opencv_LIBRARIES}
        )
