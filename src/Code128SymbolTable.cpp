#include "Code128SymbolTable.h"

int Code128SymbolTable::getStartCode() const
{
    return 104;
}

int Code128SymbolTable::getStopCode() const
{
    return 106;
}

int Code128SymbolTable::getCodeForCharacter(const unsigned char &character) const
{
    return character - 32;
}
