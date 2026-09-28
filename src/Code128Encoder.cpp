#include "Code128Encoder.h"

bool Code128SymbolTable::validateInput(std::string input)
{
    return true;
}

int Code128SymbolTable::getStartCode()
{
    return 104;
}

int Code128SymbolTable::getCodeFromCharacter(char character)
{
    return 0;
}

int Code128SymbolTable::calculateChecksum(std::vector<int> code)
{
    return 0;
}

std::vector<int> Code128SymbolTable::encode(const std::string &input)
{
    return std::vector<int>();
}