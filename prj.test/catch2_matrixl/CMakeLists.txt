add_executable(catch2_matrixl catch2_matrixl.cpp)
target_link_libraries(catch2_matrixl matrixl)
include(CTest)
include(Catch)
catch_discover_tests(catch2_matrixl)