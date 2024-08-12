#pragma once
#include "IReader.hpp"
#include "OCRModel.hpp"

namespace Reader {
    using namespace OCR;

    class ImageReader : public IReader {
    public:
        ImageReader(std::string &img_fullpath, std::string &lang_used);
        void read(std::ostream &os) override;
        ImageReader() = default;
    private:
        OCRModel _ocr_mod;
    };
}
