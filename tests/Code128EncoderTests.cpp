#include <gtest/gtest.h>
#include "Code128Encoder.h"
#include "Code128SymbolTable.h"

TEST(Code128EncoderTest, EncodesReferenceExampleFromTaskDescription)
{
    Code128SymbolTable table;
    Code128Encoder encoder(table);

    std::vector<int> expected{104, 40, 37, 44, 44, 47, 17, 18, 19, 8, 106};
    EXPECT_EQ(encoder.encode("HELLO123"), expected);
}

TEST(Code128EncoderTest, RejectsCharactersOutsideValidRange)
{
    Code128SymbolTable table;
    Code128Encoder encoder(table);

    std::string invalidString = "AB";
    invalidString += '\x01';

    EXPECT_TRUE(encoder.encode(invalidString).empty());
}

TEST(Code128EncoderTest, RejectsCharacterJustBelowLowerBoundary)
{
    Code128SymbolTable table;
    Code128Encoder encoder(table);

    std::string input(1, static_cast<char>(31));
    EXPECT_TRUE(encoder.encode(input).empty());
}

TEST(Code128EncoderTest, RejectsCharacterJustAboveUpperBoundary)
{
    Code128SymbolTable table;
    Code128Encoder encoder(table);

    std::string input(1, static_cast<char>(127));
    EXPECT_TRUE(encoder.encode(input).empty());
}

TEST(Code128SymbolTableTest, ReturnsCorrectConstants)
{
    Code128SymbolTable table;

    EXPECT_EQ(table.getStartCode(), 104);
    EXPECT_EQ(table.getStopCode(), 106);
    EXPECT_EQ(table.getChecksumModulo(), 103);
}

TEST(Code128SymbolTableTest, MapsKnownCharactersToCorrectCodeValues)
{
    Code128SymbolTable table;

    EXPECT_EQ(table.getCodeForCharacter(' '), 0);
    EXPECT_EQ(table.getCodeForCharacter('A'), 33);
    EXPECT_EQ(table.getCodeForCharacter('~'), 94);
}

TEST(Code128EncoderTest, EncodingIsDeterministic)
{
    Code128SymbolTable table;
    Code128Encoder encoder(table);

    EXPECT_EQ(encoder.encode("HELLO123"), encoder.encode("HELLO123"));
}

TEST(Code128EncoderTest, UppercaseAndLowercaseProduceDifferentResults)
{
    Code128SymbolTable table;
    Code128Encoder encoder(table);

    EXPECT_NE(encoder.encode("HELLO123"), encoder.encode("hello123"));
}