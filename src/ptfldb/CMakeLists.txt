set(lib_name "ptfldb")
add_library(${lib_name} SHARED
  io.cpp
)

target_include_directories(${lib_name} INTERFACE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(${lib_name} PRIVATE prices Qt5::Core)
target_compile_features(${lib_name} PRIVATE cxx_inline_namespaces)
set_target_properties(${lib_name} PROPERTIES POSITION_INDEPENDENT_CODE ON)
