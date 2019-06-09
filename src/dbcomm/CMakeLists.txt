add_library(dbcomm SHARED
  databaseproxy.cpp
  portfolio.cpp
  io.cpp
)

target_include_directories(dbcomm INTERFACE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(dbcomm Qt5::Core Qt5::Sql)
target_compile_features(dbcomm PRIVATE cxx_inline_namespaces)
