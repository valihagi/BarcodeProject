#ifndef CODE128ENCODER_H
#define CODE128ENCODER_H

#include <vector>

class Code128SymbolTable;

class Code128Encoder {
    private:
        const Code128SymbolTable& m_symbolTable;

        bool validateInput(const char&);
        int calculateChecksum(const std::vector<int>&);
    public: 
        explicit Code128Encoder(const Code128SymbolTable&);
        ~Code128Encoder() = default;

        std::vector<int> encode(const std::string&);
};

#endif // CODE128ENCODER_H