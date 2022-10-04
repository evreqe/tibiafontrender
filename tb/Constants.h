#pragma once

#include "common.h"

#include <SFML/Graphics.hpp>

namespace tb
{
    namespace BitmapFonts
    {
        namespace Default
        {
            const std::string FileName = "images/font.png";

            const sf::Vector2u GlyphSize(18, 19);

            // 16x6
            const std::vector<unsigned int> GlyphWidthList =
            {
                6,  4,  8,  16, 9,  18, 15, 5,  7,  7,  9,  13, 5,  8,  4,  7,
                10, 8,  10, 10, 10, 9,  10, 10, 9,  10, 4,  5,  12, 14, 12, 9,
                14, 15, 13, 13, 14, 13, 12, 15, 15, 8,  9,  15, 13, 18, 15, 14,
                12, 14, 15, 11, 14, 15, 15, 18, 15, 15, 13, 15, 14, 15, 11, 13,
                4,  9,  11, 9,  11, 9,  10, 11, 11, 6,  7,  11, 6,  16, 11, 10,
                11, 11, 8,  8,  7,  11, 11, 15, 11, 12, 10, 9,  10, 11, 14, 11,
            };
        }

        namespace Tiny
        {
            const std::string FileName = "images/font_tiny.png";

            const sf::Vector2u GlyphSize(7, 10);

            // 16x6
            const std::vector<unsigned int> GlyphWidthList =
            {
                4, 3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 6, 3, 7,
                6, 5, 6, 6, 6, 6, 6, 6, 6, 6, 3, 3, 7, 7, 7, 7,
                7, 6, 6, 6, 6, 6, 6, 6, 6, 3, 6, 7, 6, 7, 7, 6,
                6, 7, 6, 6, 7, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
                7, 6, 6, 6, 6, 6, 6, 6, 6, 3, 6, 7, 6, 7, 7, 6,
                6, 7, 6, 6, 7, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
            };
        }

        namespace Modern
        {
            const std::string FileName = "images/font_modern.png";

            const sf::Vector2u GlyphSize(16, 12);

            // 16x6
            const std::vector<unsigned int> GlyphWidthList =
            {
                3,  4, 7, 9, 8,  10, 10, 4,  6, 6, 9, 9, 4, 9,  4,  8,
                8,  6, 8, 8, 8,  8,  8,  8,  8, 8, 4, 4, 9, 9,  9,  7,
                10, 9, 8, 8, 9,  8,  8,  9,  9, 6, 7, 8, 8, 10, 9,  9,
                8,  9, 9, 8, 10, 9,  8,  10, 8, 8, 8, 6, 8, 6,  10, 10,
                4,  8, 8, 7, 8,  8,  7,  8,  8, 4, 6, 8, 4, 10, 8,  8,
                8,  8, 7, 7, 7,  8,  8,  10, 8, 8, 7, 8, 4, 8,  9,  8,
            };
        }
    }
}
