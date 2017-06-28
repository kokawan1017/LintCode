// BigIntegerMultiplication.cpp : 定义控制台应用程序的入口点。
//
/*
http://www.lintcode.com/en/problem/big-integer-multiplication/

大整数相乘

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2

Example
The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <sstream>


int charToInt(const char c)
{
    return static_cast<int>(c) - static_cast<int>('0');
}

char intToChar(const int n)
{
    return static_cast<char>(static_cast<int>('0') + (n));
}

int multiplyByChar(const char c1, const char c2)
{
    int product = charToInt(c1) * charToInt(c2);
    return product;
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

std::string multiplyByChar(const std::string& num1, const char num2)
{
    std::string result(num1.length() + 1, '0');

    auto rit = result.rbegin();
    for (auto it = num1.crbegin(); it != num1.crend(); ++it, ++rit)
    {
        int product = multiplyByChar(*it, num2);

        int productHighPos = product / 10;
        int currentPos = product % 10;

        currentPos += charToInt(*rit);

        *rit = intToChar(currentPos % 10);
        *(rit + 1) = intToChar(productHighPos + currentPos / 10);
    }

    trimFrontZero(result);
    return result;
}

void addFrontZero(std::string& str, const size_t n)
{
    std::string s(n, '0');
    str = s + str;
}

std::string addStrings(const std::string& num1, const std::string& num2)
{
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

std::string multiply(const std::string& num1, const std::string& num2)
{
    std::vector<std::string> productList;

    int power = 0;
    for (auto it = num1.crbegin(); it != num1.crend(); ++it)
    {
        std::string product = multiplyByChar(num2, *it);

        std::string zeros(power, '0');

        product += zeros;
        productList.push_back(product);

        ++power;
    }

    std::string result = "0";
    for (const auto& s : productList)
    {
        result = addStrings(result, s);
    }

    return result;
}

int main()
{
    std::string s1 = "584265841325995754";
    std::string s2 = "85259636471120325";
    char c2 = '5';
    std::cout << multiplyByChar(s1, c2) << std::endl;

    std::cout << addStrings(s1, s2) << std::endl;

    std::cout << multiply(s1, s2) << std::endl;

    std::cout << multiply("0", "0") << std::endl;
    return 0;
}

