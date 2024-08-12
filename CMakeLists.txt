cmake_minimum_required(VERSION 3.14)
project(ImageReader)

find_package(PkgConfig REQUIRED)

pkg_check_modules(tesseract REQUIRED IMPORTED_TARGET tesseract)
pkg_check_modules(leptonica REQUIRED IMPORTED_TARGET lept)
pkg_check_moduleS(libcurl REQUIRED IMPORTED_TARGET libcurl)
set_property(TARGET PkgConfig::tesseract APPEND PROPERTY INTERFACE_LINK_LIBRARIES curl)

include(cmake/UpdateSubmodules.cmake)
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(apps)
add_subdirectory(test)
