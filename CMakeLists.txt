cmake_minimum_required(VERSION 3.0.0)
project(G_proj VERSION 0.1.0)

include(CTest)
enable_testing()

set("Torch_DIR" "/home/ianbringe/Code/CPP/libtorch/share/cmake/Torch")
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(G_proj ${SRC_FILES})

target_include_directories(G_proj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(G_proj "${TORCH_LIBRARIES}")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
