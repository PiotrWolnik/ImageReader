#include <gtest/gtest.h>
#include "ImageReader.hpp"
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

TEST(ImageReaderTests, constructorNoExceptionThrownTest) {
    ASSERT_TRUE(fs::exists(PATH_TO_TEST_IMAGES)) << "Program failed due to an invalid folder path where test images are stored.";
    std::string img_fullpath = std::string(PATH_TO_TEST_IMAGES) + "test_image_1.png";
    std::string lang_used = "xyz";
    ASSERT_THROW(Reader::ImageReader img_reader(img_fullpath, lang_used), OCRFailure::OCRInitializationError);
}

TEST(ImageReaderTests, constructorExceptionThrownTest) {
    ASSERT_TRUE(fs::exists(PATH_TO_TEST_IMAGES)) << "Program failed due to an invalid folder path where test images are stored.";
    std::string img_fullpath = std::string(PATH_TO_TEST_IMAGES) + "test_image_1.png";
    std::string lang_used = "eng";
    ASSERT_NO_THROW(Reader::ImageReader img_reader(img_fullpath, lang_used));
}

TEST(ImageReaderTests, readTest) {
    ASSERT_TRUE(fs::exists(PATH_TO_TEST_IMAGES)) << "Program failed due to an invalid folder path where test images are stored.";
    std::string img_fullpath = std::string(PATH_TO_TEST_IMAGES) + "test_image_1.png";
    std::string lang_used = "eng";
    Reader::ImageReader img_reader(img_fullpath, lang_used);
    std::ostringstream os{};
    img_reader.read(os);
    EXPECT_EQ(os.str(), "It was the best of\n" \
                      "times, it was the worst\n" \
                      "of times, it was the age\n" \
                      "of wisdom, it was the\n" \
                      "age of foolishness...\n\n");
}
