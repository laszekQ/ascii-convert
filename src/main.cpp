#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include "func.h"

using char_vector = std::vector< std::vector<char> >;

int main(int argc, const char* argv[])
{
    // file_from, color mode, gradient length, mode, file_to
    // mode d - dark and l - light

    if(argc < 5)
    {
        std::cout << "Not enough arguments!\n";
        std::cout << "Usage:\n./ascii-convert [FILE_IN] [COLOR MODE] [GRADIENT LENGTH] [MODE] [FILE_OUT]\n";
        std::cout << "COLOR MODE: d - dark, l - light\n"; 
        std::cout << "GRADIENT LENGTH: from 3 to 10, the higher the value the more details there will be\n";
        std::cout << "MODE - 1 - 1:1, 2 - 2:1, 3 - 1:2\n";
        std::cout << "FILE_OUT - can be empty, which would redirect the output to the console" << std::endl;
        return -1;
    }

    const char* FILE_IN        = argv[1];
    const char  COLOR_MODE     = argv[2][0];
    const int   GRAD           = std::atoi(argv[3]);
    const char  MODE           = argv[4][0];
    const std::string GRADIENT = " .:-=+*#%@";

    if(GRAD < 2)
    {
        std::cout << "Gradient length can't be less than 2!";
        return -3;
    }

    sf::Image img_in;
    if(!img_in.loadFromFile(FILE_IN))
    {
        std::cout << "Failed to load file." << std::endl;
        return -2;
    }

    char_vector out = imgToAscii(img_in, GRADIENT, GRAD, MODE, MODE);

    if(argc == 6)
    {
        const char* FILE_OUT = argv[5]; 
        std::ofstream fout(FILE_OUT);

        for(auto row : out)
        {
            for(char c : row)
                fout << c;
            fout << '\n';
        }
        fout.close();
    }
    else
    {
        for(auto row : out)
        {
            for(char c : row)
                std::cout << c;
            std::cout << '\n';
        }
    }

    return 0;
}