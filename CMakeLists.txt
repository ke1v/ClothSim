cmake_minimum_required(VERSION 3.0.0)
project(ClothSim VERSION 0.1.0)

include(CTest)
enable_testing()
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
find_package(SFML COMPONENTS system window graphics audio REQUIRED)

include_directories(${SFML_INCLUDE_DIR})

add_executable(ClothSim main.cpp Point.hpp Point.cpp Stick.hpp Stick.cpp)

target_link_libraries(ClothSim ${SFML_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
