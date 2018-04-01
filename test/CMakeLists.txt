############### Boost Unit Tests #################

find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories (${CMAKE_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIRS}
    )

add_definitions (-DBOOST_TEST_DYN_LINK)

# Executables

add_executable (testTimeUtils testTimeUtils.cpp)
target_link_libraries (testTimeUtils
    yahoo-finance
    curl
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    )

add_executable (testQuote testQuote.cpp)
target_link_libraries (testQuote
    yahoo-finance
    curl
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    )
