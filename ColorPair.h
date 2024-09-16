#pragma once
#include <string>
#include <iomanip>
#include<sstream>
#include <iostream>

namespace TelCoColorCoder
{
    const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

    int getMaxLen(const char* a[])
    {
        int minorWidth = std::strlen(a[0]);
        for (int i = 0; i < sizeof(*a); i++)
        {
            if (minorWidth < strlen(a[i]))minorWidth = strlen(a[i]);
        }return minorWidth;
    }
    std::stringstream printColorMap() {
        int majorWidth = std::strlen(majorColor[0]);
        int minorWidth = std::strlen(minorColor[0]);
        minorWidth = getMaxLen(minorColor);
        majorWidth = getMaxLen(majorColor);
        std::stringstream s;
        int i = 0, j = 0;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {

                s << std::setw(2) << i * 5 + j << " | " << std::setw(majorWidth) << majorColor[i] << " | " << std::setw(minorWidth) << minorColor[j] << "\n";
            }
        }
        std::cout << s.str();
        return s;
    }
    std::string getMajor(int n)
    {
        return majorColor[n];
    }
    std::string getMinor(int n)
    {
        return minorColor[n];
    }
}

