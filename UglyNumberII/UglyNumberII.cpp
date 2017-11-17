// UglyNumberII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

int my_min(int a, int b)
{
    return a < b ? a : b;
}

int my_min(int a, int b, int c)
{
    return my_min(my_min(a, b), c);
}

bool isUgly(int n)
{
    if (n <= 0)
    {
        return false;
    }

    while (n % 2 == 0)
    {
        n /= 2;
    }

    while (n % 3 == 0)
    {
        n /= 3;
    }

    while (n % 5 == 0)
    {
        n /= 5;
    }

    return 1 == n;
}

int nthUglyNumber(int n)
{
    // write your code here
    int nth = 0;
    int ugly = 1;
    while (true)
    {
        if (isUgly(ugly))
        {
            ++nth;
        }
        if (nth == n)
        {
            break;
        }
        ++ugly;
    }
    return ugly;
}

int nthUglyNumber_2(int n)
{
    std::vector<int> uglyNumbers;
    uglyNumbers.push_back(1);

    size_t i2 = 0;
    size_t i3 = 0;
    size_t i5 = 0;

    while (uglyNumbers.size() < n)
    {
        int nextUgly = my_min(uglyNumbers[i2] * 2, uglyNumbers[i3] * 3, uglyNumbers[i5] * 5);
        uglyNumbers.push_back(nextUgly);
        while (nextUgly == uglyNumbers[i2] * 2)
        {
            ++i2;
        }
        while (nextUgly == uglyNumbers[i3] * 3)
        {
            ++i3;
        }
        while (nextUgly == uglyNumbers[i5] * 5)
        {
            ++i5;
        }
    }
    return uglyNumbers.back();
}

int main()
{
    // 1665->1898437500
    std::cout << nthUglyNumber_2(1665) << std::endl;
    return 0;
}
