include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)

add_executable(tests ParserTest.cpp IpStorageTest.cpp)

target_include_directories(
    tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(
    tests
    GTest::gtest_main
    ipv4_storage
)

add_test(tests tests)



