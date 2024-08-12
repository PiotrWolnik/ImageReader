set(PATH_TO_APP_IMAGES "${PROJECT_SOURCE_DIR}/apps/images/")

add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_compile_definitions(${PROJECT_NAME} PUBLIC PATH_TO_APP_IMAGES="${PATH_TO_APP_IMAGES}")
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
