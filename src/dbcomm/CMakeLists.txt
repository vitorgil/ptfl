add_library(dbcomm SHARED
  databaseproxy.cpp
  portfolio.cpp
  io.cpp
)

target_include_directories(dbcomm INTERFACE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(dbcomm PRIVATE prices Qt5::Core)
target_compile_features(dbcomm PRIVATE cxx_inline_namespaces)
set_target_properties(dbcomm PROPERTIES POSITION_INDEPENDENT_CODE ON)
