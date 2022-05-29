# Download and unpack googletest at configure time
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include sources directory
include_directories(${CMAKE_SOURCE_DIR}/src)

# Create executables for each test file
file(GLOB TEST_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
foreach(TEST_SOURCE_FILE ${TEST_SOURCES})
    string(REPLACE ".cpp" "" TEST_NAME ${TEST_SOURCE_FILE})
    add_executable(${TEST_NAME} ${TEST_SOURCE_FILE})
    target_link_libraries(${TEST_NAME} yahoo-finance curl gtest_main)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach(TEST_SOURCE_FILE ${TEST_SOURCES})
