add_executable(catch2_queuea catch2_queuea.cpp)
target_link_libraries(catch2_queuea queuea)
include(CTest)
include(Catch)
catch_discover_tests(catch2_queuea)