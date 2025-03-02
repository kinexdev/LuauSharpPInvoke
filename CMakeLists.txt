cmake_minimum_required (VERSION 3.8)

project ("luau")

add_subdirectory(luau)
add_library(luau SHARED "luau.cpp" "luau.h")
target_link_libraries(luau PRIVATE Luau.VM Luau.Compiler)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET luau PROPERTY CXX_STANDARD 20)
endif()