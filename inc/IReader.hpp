#pragma once
#include <string>

namespace Reader {
    struct IReader {
        virtual void read(std::ostream &os) = 0;
        virtual ~IReader() = default;
    };
}
