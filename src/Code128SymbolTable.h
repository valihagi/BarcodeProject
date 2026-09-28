#ifndef CODE128SYMBOLTABLE_H
#define CODE128SYMBOLTABLE_H

class Code128SymbolTable {
    public: 
        Code128SymbolTable() = default;
        ~Code128SymbolTable() = default;

        int getStartCode() const;
        int getStopCode() const;
        int getCodeForCharacter(const unsigned char&) const;
};

#endif // CODE128SYMBOLTABLE_H