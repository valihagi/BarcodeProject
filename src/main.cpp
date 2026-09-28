#include <iostream>
#include <string>

int main()
{
    std::string input;
    
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

        std::cout << "You entered " << input << "\n------------\n\n";
    }
}
