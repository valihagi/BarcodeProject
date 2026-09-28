#include "Code128SymbolTable.h"

int Code128SymbolTable::getStartCode() const
{
    return START_CODE;
}

int Code128SymbolTable::getStopCode() const
{
    return STOP_CODE;
}

int Code128SymbolTable::getChecksumModulo() const
{
    return CHECKSUM_MODULO;
}

int Code128SymbolTable::getCodeForCharacter(const unsigned char &character) const
{
    return character - ASCII_OFFSET;
}
