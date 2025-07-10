#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <vector>
#include <initializer_list>

using char_vector = std::vector< std::vector<char> >;

const int COLOR_RANGE = 255;

int getBrightness(const sf::Color &pixel)
{
    int r = pixel.r;
    int g = pixel.g;
    int b = pixel.b;
    int bright = (r + g + b) / 3;

    return bright;
}

char pixelsToASCII(std::initializer_list<sf::Color> pixels, 
                   const std::string &gradient, const char c_mode)
{
    float bright = 0;
    for(const auto& pixel : pixels)
        bright += getBrightness(pixel);
    bright /= pixels.size();

    float step = COLOR_RANGE / (gradient.length() - 1);
    int index = bright / step;

    // reverse the index depending on color mode
    if(c_mode == 'd')
        index = gradient.length() - index - 1;
    
    return gradient[index];
}

char_vector imgToAscii(const sf::Image &img, std::string gradient,
                       const int grad_len, const char c_mode, const char mode)
{
    const uint32_t WIDTH  = img.getSize().x;
    const uint32_t HEIGHT = img.getSize().y;
    uint32_t height = HEIGHT / (1 + (mode == '2'));
    uint32_t width = WIDTH * (1 + (mode == '3'));
    char_vector out(height, std::vector<char>(width));

    gradient = gradient.substr(0, grad_len);

    // in 2:1 (mode = 2) we need to convert 2 pixels into 1 char,
    // therefore, the iterator must be incremented by 2 instead 1
    int step_y = 1 + (mode == '2');

    for(uint32_t i = 0; i <= HEIGHT - step_y; i += step_y)
    {
        int x = 0;
        for(uint32_t j = 0; j < WIDTH; j++)
        {
            char c = ' ';
            int y = i;
            switch(mode)
            {
            case '1':
            {
                sf::Color pixel = img.getPixel({j, i});
                c = pixelsToASCII({pixel}, gradient, c_mode);
                out[i][j] = c;
                break;
            }
            case '2':
            {
                sf::Color pixel1 = img.getPixel({j, i});
                sf::Color pixel2 = img.getPixel({j, i + 1});
                c = pixelsToASCII({pixel1, pixel2}, gradient, c_mode);
                y /= 2;
                out[y][j] = c;
                break;
            }
            case '3':
            {
                sf::Color pixel = img.getPixel({j, i}); 
                c = pixelsToASCII({pixel}, gradient, c_mode);
                out[i][x] = c;
                out[i][x + 1] = c;
                x += 2;
                break;
            }
            default:
                return out;
            }
        }
    }

    return out;
}