add_executable(catch2_matrixa catch2_matrixa.cpp)
target_link_libraries(catch2_matrixa matrixa)
include(CTest)
include(Catch)
catch_discover_tests(catch2_matrixa)