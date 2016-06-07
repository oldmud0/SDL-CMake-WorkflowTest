cmake_minimum_required(VERSION 2.8.4)
project(WorkflowTest)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules;${CMAKE_MODULE_PATH}")
set(SDL2_PATH "${PROJECT_SOURCE_DIR}/SDL")

find_package(SDL2 REQUIRED)
#find_package(SDL2_image)

add_executable(WorkflowTest src/main.cpp)

include_directories(WorkflowTest
                    ${SDL2_INCLUDE_DIR}
                    ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(WorkflowTest
                      ${SDL2_LIBRARY})