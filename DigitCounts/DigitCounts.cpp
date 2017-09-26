// DigitCounts.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

int countOne(int n, int k)
{
    if (0 == n)
    {
        if (0 == k)
        {
            return 1;
        }
        return 0;
    }

    int count = 0;
    while (n > 0)
    {
        if (n % 10 == k)
        {
            ++count;
        }
        n /= 10;
    }
    return count;
}

int digitCounts(int k, int n)
{
    // write your code here
    int count = 0;
    for (int i = 0; i <= n; ++i)
    {
        count += countOne(i, k);
    }
    return count;
}

int main()
{
    std::cout << digitCounts(1, 12) << std::endl;
    return 0;
}
