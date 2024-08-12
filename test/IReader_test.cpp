#include <gmock/gmock.h>
#include "IReader.hpp"
#include <sstream>

class MockReader : public Reader::IReader {
public:
    MOCK_METHOD(void, read, (std::ostream& os), (override));
};

TEST(MockReaderTest, readTest) {
    MockReader mock_reader;
    std::ostringstream os1{};
    std::ostringstream os2{};
    EXPECT_CALL(mock_reader, read(::testing::_))
        .WillOnce(::testing::Invoke([&os1](std::ostream& os){
            os << "Data 1 was read.\n";
        }))
        .WillOnce(::testing::Invoke([&os2](std::ostream& os){
            os << "Data 2 was read as well.\n";
        }));
    
    mock_reader.read(os1);
    mock_reader.read(os2);

    EXPECT_EQ(os1.str(), "Data 1 was read.\n");
    EXPECT_EQ(os2.str(), "Data 2 was read as well.\n");
}
