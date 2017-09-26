// UglyNumberII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

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

int main()
{
    std::cout << nthUglyNumber(1665) << std::endl;
    return 0;
}
