#include <gtest/gtest.h>
#include "OCRModel.hpp"
#include <filesystem>
#include <stdexcept>

namespace fs = std::filesystem;

// #ifdef PATH_TO_TEST_IMAGES
std::string test_files_directory = PATH_TO_TEST_IMAGES;
// #endif

TEST(OCRModelTest, constructorExceptionThrownTest)
{
    std::cout << "Checking if directory exists: " << test_files_directory << std::endl;
    ASSERT_TRUE(fs::exists(test_files_directory)) << "Program failed due to an invalid folder path where test images are stored.";
    std::string img_fullpath = test_files_directory + "test_image_1.png";
    std::string lang_used = "xyz";
    ASSERT_THROW(OCR::OCRModel ocr_model(img_fullpath, lang_used), OCRFailure::OCRInitializationError);
}

TEST(OCRModelTest, constructorNoExceptionThrownTest)
{
    ASSERT_TRUE(fs::exists(test_files_directory)) << "Program failed due to an invalid folder path where test images are stored.";
    std::string img_fullpath = test_files_directory + "test_image_1.png";
    std::string lang_used = "eng";
    ASSERT_NO_THROW(OCR::OCRModel ocr_model(img_fullpath, lang_used));
}

TEST(OCRModelTest, moveConstructorTest)
{
    ASSERT_TRUE(fs::exists(test_files_directory)) << "Program failed due to an invalid folder path where test images are stored.";
    std::string img_fullpath = test_files_directory + "test_image_1.png";
    std::string lang_used = "eng";
    OCR::OCRModel ocr_model_to_be_moved{img_fullpath, lang_used};

    OCR::OCRModel ocr_model{std::move(ocr_model_to_be_moved)};
    ASSERT_FALSE(ocr_model_to_be_moved.is_api_valid());
    ASSERT_TRUE(ocr_model.is_api_valid());
}

TEST(OCRModelTest, moveAssignmentOperator)
{
    ASSERT_TRUE(fs::exists(test_files_directory)) << "Program failed due to an invalid folder path where test images are stored.";
    std::string img_fullpath = test_files_directory + "test_image_1.png";
    std::string lang_used = "eng";
    OCR::OCRModel ocr_model_to_be_moved{img_fullpath, lang_used};

    std::string img_fullpath_second = test_files_directory+"test_image_2.jpeg";
    OCR::OCRModel ocr_model{img_fullpath_second, lang_used};
    ocr_model = std::move(ocr_model_to_be_moved);
    ASSERT_FALSE(ocr_model_to_be_moved.is_api_valid());
    ASSERT_TRUE(ocr_model.is_api_valid());
}

TEST(OCRModelTest, getOutputPNGFileTest)
{
    ASSERT_TRUE(fs::exists(test_files_directory)) << "Program failed due to an invalid folder path where test images are stored.";
    std::string img_fullpath = test_files_directory + "test_image_1.png";
    std::string lang_used = "eng";
    OCR::OCRModel ocr_model{img_fullpath, lang_used};
    std::string result = ocr_model.getOutput();
    EXPECT_EQ(result, "It was the best of\n" \
                      "times, it was the worst\n" \
                      "of times, it was the age\n" \
                      "of wisdom, it was the\n" \
                      "age of foolishness...\n");
}

TEST(OCRModelTest, getOutputJPEGFileTest)
{
    ASSERT_TRUE(fs::exists(test_files_directory)) << "Program failed due to an invalid folder path where test images are stored.";
    std::string img_fullpath = test_files_directory + "test_image_2.jpeg";
    std::string lang_used = "eng";
    OCR::OCRModel ocr_model{img_fullpath, lang_used};
    std::string result = ocr_model.getOutput();
    EXPECT_EQ(result, "A library developer will often have a very good idea of the kind of things that\n" \
                      "are expected and that can go wrong. Why not use this knowledge to make life\n" \
                      "easier for library users?\n");
}
