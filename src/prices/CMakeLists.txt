add_library(prices SHARED
  pricesapi.cpp
)

target_include_directories(prices INTERFACE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(prices PRIVATE Qt5::Core Qt5::Network)
target_compile_features(prices PRIVATE cxx_inline_namespaces)
set_target_properties(prices PROPERTIES POSITION_INDEPENDENT_CODE ON)
