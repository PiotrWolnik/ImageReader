#include "OCRModel.hpp"

OCR::OCRModel::OCRModel(std::string &img_fullpath, std::string &lang_used)
    : _api(std::make_unique<tesseract::TessBaseAPI>())
{
    if (_api->Init(NULL, lang_used.c_str()))
        throw OCRFailure::OCRInitializationError();

    auto delPix = [](Pix *img){ pixDestroy(&img); };
    std::unique_ptr<Pix, decltype(delPix)> image(pixRead(img_fullpath.c_str()), delPix);
    _api->SetImage(image.get());
    _output = _api->GetUTF8Text();
}

OCR::OCRModel::~OCRModel()
{
    if (_api)
        _api->End();
}

OCR::OCRModel::OCRModel(OCRModel &&ocr_m)
    : _api(std::move(ocr_m._api)), _output(std::move(ocr_m._output))
{
}

OCR::OCRModel &OCR::OCRModel::operator=(OCRModel &&ocr_m)
{
    if (this == &ocr_m) return *this;

    _api = std::move(ocr_m._api);
    _output = std::move(ocr_m._output);

    return *this;
}

std::string OCR::OCRModel::getOutput()
{
    return _output;
}
