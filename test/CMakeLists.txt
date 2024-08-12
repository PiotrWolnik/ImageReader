set(SOURCE_TEST_FILES
    ImageReader_test.cpp
    IReader_test.cpp
    OCRModel_test.cpp
)

enable_testing()

set(PATH_TO_TEST_IMAGES "${PROJECT_SOURCE_DIR}/test/test_images/")

add_executable(${PROJECT_NAME}_Tests ${SOURCE_TEST_FILES})
target_compile_features(${PROJECT_NAME}_Tests PUBLIC cxx_std_20)
target_compile_definitions(${PROJECT_NAME}_Tests PRIVATE PATH_TO_TEST_IMAGES="${PATH_TO_TEST_IMAGES}")
target_link_libraries(${PROJECT_NAME}_Tests GTest::gtest_main GTest::gmock_main ${PROJECT_NAME}_lib)
set_target_properties(${PROJECT_NAME}_Tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_Tests)
