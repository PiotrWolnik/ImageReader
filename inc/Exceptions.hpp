#pragma once
#include <stdexcept>

namespace OCRFailure {
    
    class OCRInitializationError : public std::exception {
    public:
        virtual const char* what() const noexcept {
            return "Could not initialize tesseract.\n";
        }
    };

}