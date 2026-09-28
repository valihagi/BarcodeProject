#ifndef CODE128SYMBOLTABLE_H
#define CODE128SYMBOLTABLE_H

class Code128SymbolTable {
    public: 
        Code128SymbolTable();
        ~Code128SymbolTable();

        int getStartCode();
        int getStopCode();
        int getCodeForCharacter(const unsigned char&);
};

#endif // CODE128SYMBOLTABLE_H