cmake_minimum_required (VERSION 3.8)
project ("task3")
set(CMAKE_CXX_STANDART 11)
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)
add_executable (task3 "main.cpp")
target_link_libraries(task3 PRIVATE nlohmann_json::nlohmann_json)

