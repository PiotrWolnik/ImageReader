cmake_minimum_required(VERSION 3.14)
project(PDFReader)

include(cmake/UpdateSubmodules.cmake)
add_subdirectory(external)
add_subdirectory(test)
