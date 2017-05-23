cmake_minimum_required(VERSION 2.8)
project(EdWebserver)
set(EdWebserver_MAJOR_VERSION 0)
set(EdWebserver_MINOR_VERSION 1)
set(EdWebserver_PATCH_VERSION 0)
set(EdWebserver_VERSION
  ${EdWebserver_MAJOR_VERSION}.${EdWebserver_MINOR_VERSION}.${EdWebserver_PATCH_VERSION})
#add_executable (edwebserver main.cpp $<TARGET_OBJECTS:ConsoleManagerObjs> $<TARGET_OBJECTS:ThreadObjs>)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.45.0 COMPONENTS regex)
include_directories(${Boost_INCLUDE_DIRS}) 
find_package (Threads)
#add_executable (edwebserver main.cpp $<TARGET_OBJECTS:ConsoleManagerObjs> $<TARGET_OBJECTS:WebServerObjs>)

add_executable (edwebserver main.cpp web_directory.cpp response.cpp request.cpp)
#target_include_directories(edwebserver PUBLIC
# ${CMAKE_CURRENT_SOURCE_DIR}/common 
# ${CMAKE_CURRENT_SOURCE_DIR}/ui/cli/api
# ${CMAKE_CURRENT_SOURCE_DIR}/web
# ${CMAKE_CURRENT_SOURCE_DIR}/sal/api
#)
target_link_libraries(edwebserver ${CMAKE_THREAD_LIBS_INIT} ${Boost_REGEX_LIBRARY})
# compile with c++11
add_definitions(-std=c++11)
target_compile_features(edwebserver PRIVATE cxx_range_for)
#add_subdirectory (sal)
#add_subdirectory (ui)
#add_subdirectory (web)
