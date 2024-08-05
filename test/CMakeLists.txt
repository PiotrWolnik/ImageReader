set(SOURCE_TEST_FILES
    ex_test.cpp
)

enable_testing()

add_executable(${PROJECT_NAME}_Tests ${SOURCE_TEST_FILES})
target_link_libraries(${PROJECT_NAME}_Tests GTest::gtest_main GTest::gmock_main)
set_target_properties(${PROJECT_NAME}_Tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_Tests)
