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

        std::cout << "You entered ";
        for (int code : encoder.encode(input))
        {
           std::cout << code << " ";
        }
        std::cout << "\n------------\n\n";
    }
}
