#include <assert.h>
#include <iomanip>
#include <iostream>
#include<sstream>
#include <vector>
#include "ColorPair.h"
using namespace TelCoColorCoder;
std::string trim(std::string m)
{
    std::string y = "";
    for (int i = 0; i < m.length(); i++)
    {
        if (m[i] != ' ')y += m[i];
    }return y;
}

int getMajorIndex(std::string s)
{
    int m = atoi(s.c_str());
    return (m / 5);
}
int getMinorIndex(std::string s)
{
    int m = atoi(s.c_str());
    return (m % 10);
}
std::vector<std::string> splitStrings(std::stringstream& result, char delimiter)
{
    std::vector<std::string> strings;
    std::string m;
    while (std::getline(result, m, delimiter)) {
        strings.push_back(trim(m));
    }
    return strings;
}

void TestColorPairPrint()
{
    std::stringstream result = printColorMap();
    std::vector<std::string> strings = splitStrings(result, '\n');
    assert(strings.size() == 25);

    for (int i = 0; i < strings.size(); i++)
    {
        std::stringstream k(strings[i]);
        std::vector<std::string> printSt = splitStrings(k, '|');
        assert(printSt.size() == 3);
        int minor = getMinorIndex(printSt[0]);
        int major = getMajorIndex(printSt[0]);
        assert(printSt[1] == getMajor(major));
        assert(printSt[2] == getMinor(minor));
    }


}
int main() {
    TestColorPairPrint();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
