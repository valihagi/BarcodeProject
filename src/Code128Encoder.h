#ifndef CODE128ENCODER_H
#define CODE128ENCODER_H

#include <vector>

class Code128SymbolTable {
    private:
        bool validateInput(std::string);
        int getStartCode();
        int getCodeFromCharacter(char character);
        int calculateChecksum(std::vector<int> code);
    public: 
        Code128SymbolTable();
        ~Code128SymbolTable();

        std::vector<int> encode(const std::string &input);
};

#endif // CODE128ENCODER_H