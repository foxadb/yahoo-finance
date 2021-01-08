# Download and unpack googletest at configure time
configure_file(gtest/CMakeLists.txt googletest-download/CMakeLists.txt)
execute_process(
    COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(
    COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(
    ${CMAKE_CURRENT_BINARY_DIR}/googletest-src
    ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
    EXCLUDE_FROM_ALL
)

# Include sources directory
include_directories(${CMAKE_SOURCE_DIR}/src)

# Create test executables
add_executable(testTimeUtils testTimeUtils.cpp)
target_link_libraries(testTimeUtils yahoo-finance curl gtest_main)

add_executable(testQuote testQuote.cpp)
target_link_libraries(testQuote yahoo-finance curl gtest_main)
