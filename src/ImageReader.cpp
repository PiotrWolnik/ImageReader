#include "ImageReader.hpp"

Reader::ImageReader::ImageReader(std::string &img_fullpath, std::string &lang_used)
    : _ocr_mod(img_fullpath, lang_used)
{
}

void Reader::ImageReader::read(std::ostream &os)
{
    os << _ocr_mod.getOutput() + "\n";
}
