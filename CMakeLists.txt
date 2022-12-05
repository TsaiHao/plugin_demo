project(plugin_demo)

set(CMAKE_CXX_STANDARD 17)

add_library(plugin plugin/registry.cpp plugin/instances/a.cpp)

add_executable(demo main.cpp)

target_link_libraries(demo plugin)