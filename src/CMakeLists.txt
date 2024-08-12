add_definitions( -DABSOLUTE_PATH=${PROJECT_SOURCE_DIR} )

set(LIB_SOURCE_FILES
    ImageReader.cpp
    OCRModel.cpp
)

add_library(${PROJECT_NAME}_lib STATIC ${LIB_SOURCE_FILES})
target_compile_features(${PROJECT_NAME}_lib PUBLIC cxx_std_20)
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(${PROJECT_NAME}_lib PRIVATE PkgConfig::tesseract PkgConfig::leptonica)
set_target_properties(${PROJECT_NAME}_lib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
