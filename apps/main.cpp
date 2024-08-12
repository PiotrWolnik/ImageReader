#include <iostream>
#include "ImageReader.hpp"
#include <filesystem>

namespace fs = std::filesystem;

static std::string path_to_images = PATH_TO_APP_IMAGES;

int main() {
    std::string path_to_img = path_to_images + "image.png";
    std::string lang_used_in_the_img = "eng";
    Reader::ImageReader img_reader{path_to_img, lang_used_in_the_img};
    img_reader.read(std::cout);
    return EXIT_SUCCESS;
}