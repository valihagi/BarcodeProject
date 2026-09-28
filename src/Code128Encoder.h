#ifndef CODE128ENCODER_H
#define CODE128ENCODER_H

#include <vector>

class Code128SymbolTable;

class Code128Encoder {
    private:
        Code128SymbolTable& m_symbolTable;

        bool validateInput(const char&);
        int calculateChecksum(std::vector<int>);
    public: 
        Code128Encoder();
        ~Code128Encoder();

        std::vector<int> encode(const std::string&);
};

#endif // CODE128ENCODER_H