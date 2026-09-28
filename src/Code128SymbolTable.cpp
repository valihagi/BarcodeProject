#include "Code128SymbolTable.h"

int Code128SymbolTable::getStartCode()
{
    return 104;
}

int Code128SymbolTable::getStopCode()
{
    return 106;
}

int Code128SymbolTable::getCodeForCharacter(const unsigned char &character)
{
    return character - 32;
}
