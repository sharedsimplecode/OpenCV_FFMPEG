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
#
# #
# find_package(CUDA)
#
#
# # boost
# SET(BOOST_ROOT "$ENV{HOME}/Project/libs/boost/boost_1.65")
# SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} ${BOOST_ROOT}/include)
# SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} ${BOOST_ROOT}/lib)
# FIND_PACKAGE(Boost COMPONENTS system filesystem)
# IF (Boost_FOUND)
# 	message(STATUS "boost found")
#     INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
#     ADD_DEFINITIONS( "-DHAS_BOOST" )
# ENDIF()
#
#
#
#
#
# # SOURCE FILES
# # SOURCE FILES
# # file(GLOB TOOLS 		RELATIVE "tools" 	"*.cpp")
# # file(GLOB CMVUVSS 		RELATIVE "cmvuvss" 	"*.cpp")
# # file(GLOB CMVUVSS_H 	RELATIVE "cmvuvss" 	"*.h")
# # file(GLOB NLOHMANN_H 	RELATIVE "nlohmann"	"*.hpp")
# # file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp")
# # file(GLOB TOOLS RELATIVE tools 	"*.cpp")
# # file(GLOB SOURCES RELATIVE src 	"*.cpp")
# # file(GLOB REMOVE_FILES src/CMvUvss/CMvUvss__.cpp src/CMvUvss/CMvUvss__.h)
# # list(REMOVE_ITEM list ${to_remove})
#
# message(STATUS "${TOOLS} ${NLOHMANN_H}")
#
#
set(SOURCES tools/main.cpp
            src/rtspstreamer.cpp)
# 			src/misc/func.cpp src/misc/drawtool.cpp
# 			src/detector/detector_yolov4.cpp
# 			src/detector/yolov4_wrapper.cpp
# 			src/detector/detector2.cpp
# 			src/detector/YOLOWrapper.cpp
# 			src/datawrapper/detectedframe.cpp)
#
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/src )
add_executable( OTHER_main  ${SOURCES})
#
#
target_link_libraries(OTHER_main
                      ${OpenCV_LIBS}
                      glog tbb)
						# ${OpenCV_LIBS} ${Boost_LIBRARIES}
						# glog pthread tbb
					  #  	-L${CMAKE_CURRENT_SOURCE_DIR}/src/cmvuvss
				    # 	-lhpsocket
						# -lMvCarCheckSDK
						# -ldarknet)
#
#
#
#
# # configure_file(RemoteDevConfig.xml RemoteDevConfig.xml COPYONLY)
#
#
# # copy and make symbolic link for *.so libraries
# ##########################################################################
# configure_file(src/cmvuvss/libhpsocket.so libhpsocket.so COPYONLY)
# configure_file(src/cmvuvss/libMvCarCheckSDK.so libMvCarCheckSDK.so COPYONLY)
# configure_file(src/detector/darknet/libdarknet.so libdarknet.so COPYONLY)
#
# SET( legacy_link   ${CMAKE_CURRENT_SOURCE_DIR}/build/libMvCarCheckSDK.so	${CMAKE_CURRENT_SOURCE_DIR}/build/libhpsocket.so)
# SET( legacy_target ${CMAKE_CURRENT_SOURCE_DIR}/build/libMvCarCheckSDK.so.2	${CMAKE_CURRENT_SOURCE_DIR}/build/libhpsocket.so.5)
#
# foreach (l t IN ZIP_LISTS legacy_link legacy_target)
# 	message(STATUS "en=${l}, ba=${t}")
# 	ADD_CUSTOM_COMMAND( TARGET UVSS_detection POST_BUILD# OUTPUT ${legacy_link}
# 					COMMAND ln -snf ${l} ${t}
# 					COMMENT "ln -snf ${l} ${t}")
# endforeach()
#
#
# # COPY config directory to build
# # ########################################################################
# ADD_CUSTOM_COMMAND( TARGET UVSS_detection POST_BUILD# OUTPUT ${legacy_link}
# 				COMMAND cp -r ${CMAKE_CURRENT_SOURCE_DIR}/config ${CMAKE_CURRENT_SOURCE_DIR}/build/
# 				COMMENT "cp -r config ")
#
#
# ADD_CUSTOM_COMMAND( TARGET UVSS_detection POST_BUILD# OUTPUT ${legacy_link}
# 				COMMAND cp -r ${CMAKE_CURRENT_SOURCE_DIR}/yolov4mish416 ${CMAKE_CURRENT_SOURCE_DIR}/build/
# 				COMMENT "cp -r config ")
