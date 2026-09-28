#ifndef CODE128SYMBOLTABLE_H
#define CODE128SYMBOLTABLE_H

class Code128SymbolTable {
    private:
        static constexpr int START_CODE = 104;
        static constexpr int STOP_CODE = 106;
        static constexpr int ASCII_OFFSET = 32;
        static constexpr int CHECKSUM_MODULO = 103;

    public: 
        Code128SymbolTable() = default;
        ~Code128SymbolTable() = default;

        int getStartCode() const;
        int getStopCode() const;
        int getChecksumModulo() const;
        int getCodeForCharacter(const unsigned char&) const;
};

#endif // CODE128SYMBOLTABLE_H