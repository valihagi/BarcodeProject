#include "Code128Encoder.h"
#include "Code128SymbolTable.h"

Code128Encoder::Code128Encoder(const Code128SymbolTable& symbolTable) : m_symbolTable(symbolTable)
{}

bool Code128Encoder::validateInput(const char& character)
{

    if (character < 32 || character > 126)
    {
        return false;
    }
    return true;
}

int Code128Encoder::calculateChecksum(std::vector<int> code)
{
    int checksum = m_symbolTable.getStartCode();
    for (size_t index = 1; index < code.size(); index++)
    {
        checksum += index * code[index];
    }

    return checksum % m_symbolTable.getChecksumModulo();
}

std::vector<int> Code128Encoder::encode(const std::string &input)
{
    std::vector<int> code{m_symbolTable.getStartCode()};

    for (const unsigned char& c : input)
    {
        if (validateInput(c) == false)
        {
            return std::vector<int>();
        }
        code.push_back(m_symbolTable.getCodeForCharacter(c));
    }

    code.push_back(calculateChecksum(code));
    code.push_back(m_symbolTable.getStopCode());
    return code;
}