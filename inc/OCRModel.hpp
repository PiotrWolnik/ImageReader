#pragma once
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <memory>
#include "Exceptions.hpp"
#include <functional>
#include <type_traits>

namespace OCR {
    class OCRModel {
    public:
        OCRModel(std::string &img_fullpath, std::string &lang_used);
        
        // Non-copyable
        OCRModel(OCRModel const&) = delete;
        OCRModel& operator=(OCRModel const&) = delete;

        // Only moveable
        OCRModel(OCRModel &&);
        OCRModel& operator=(OCRModel &&);

        std::string getOutput();
        ~OCRModel();

        std::function<bool(void)> is_api_valid {
            [&]()->bool {
                return (_api) ? true : false;
            }
        };
    private:
        std::unique_ptr<tesseract::TessBaseAPI> _api;
        std::string _output;
    };
}
