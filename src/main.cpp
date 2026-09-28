#include <iostream>
#include <string>
#include "Code128Encoder.h"
#include "Code128SymbolTable.h"

int main()
{
    std::string input;
    Code128SymbolTable symbolTable{};
    Code128Encoder encoder(symbolTable);
    
    while(true)
    {
        std::cout << "Please enter an ASCII string or type \"quit\" to exit: ";
        std::getline(std::cin, input);

        //tolowercase
        std::transform(input.begin(), input.end(), input.begin(),::tolower);
        if (input == "quit")
        {
            break;
        }
        std::vector<int> code128 =  encoder.encode(input);
        if (code128.size() == 0)
        {
            std::cout << "You either entered and empty or an invalid string! Please try again.";
            continue;
        }

        std::cout << "You entered ";
        for (const int code : code128)
        {
           std::cout << code << " ";
        }
        std::cout << "\n------------\n\n";
    }
}
