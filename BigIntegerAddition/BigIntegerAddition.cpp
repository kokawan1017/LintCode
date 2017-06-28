// BigIntegerAddition.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <algorithm>

int charToInt(const char c)
{
    return static_cast<int>(c) - static_cast<int>('0');
}

char intToChar(const int n)
{
    return static_cast<char>(static_cast<int>('0') + (n));
}

int addByChar(const char c1, const char c2)
{
    int sum = charToInt(c1) + charToInt(c2);
    return sum;
}

void trimFrontZero(std::string& str)
{
    size_t pos = str.find_first_not_of('0');
    if (pos != std::string::npos)
    {
        str = str.substr(pos);
    }
    else
    {
        str = "0";
    }
}

void addFrontZero(std::string& str, const size_t n)
{
    std::string s(n, '0');
    str = s + str;
}

std::string addStrings(std::string& num1, std::string& num2)
{
    // Write your code here
    size_t resultLengh = std::max(num1.length(), num2.length()) + 1;
    std::string result(resultLengh, '0');

    std::string shorter = num1;
    std::string longer = num2;
    if (shorter.length() > longer.length())
    {
        std::swap(shorter, longer);
    }
    addFrontZero(shorter, longer.length() - shorter.length());

    auto it1 = shorter.rbegin();
    auto it2 = longer.rbegin();
    auto rit = result.rbegin();
    for (; it1 != shorter.rend(); ++it1, ++it2, ++rit)
    {
        int sum = addByChar(*it1, *it2);

        int sumHighPos = sum / 10;
        int currentPos = sum % 10;

        currentPos += charToInt(*rit);

        *rit = intToChar(currentPos % 10);
        *(rit + 1) = intToChar(sumHighPos + currentPos / 10);
    }

    trimFrontZero(result);
    return result;

}
int main()
{
    return 0;
}

