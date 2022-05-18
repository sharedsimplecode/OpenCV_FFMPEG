cmake_minimum_required(VERSION 3.17)
project( OTHER )
#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)
#
#
# # opencv
find_package( OpenCV REQUIRED )
set(SOURCES tools/main.cpp
            src/rtspstreamer.cpp)

include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/src )
add_executable( OTHER_main  ${SOURCES})
#
#
target_link_libraries(OTHER_main
                      ${OpenCV_LIBS}
                      glog tbb)
