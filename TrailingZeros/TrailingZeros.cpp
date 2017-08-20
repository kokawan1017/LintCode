// TrailingZeros.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>

int countX(long long n, long long x)
{
    int count = 0;
    while (n % x == 0 && n >= x)
    {
        ++count;
        n /= x;
    }

    return count;
}

long long trailingZeros(long long n)
{
    // write your code here, try to do it without arithmetic operators.
    long long count2 = 0;
    for (long long i = 2; i <= n; i += 2)
    {
        count2 += countX(i, 2);
    }

    long long count5 = 0;
    for (long long i = 5; i <= n; i += 5)
    {
        count5 += countX(i, 5);
    }
    return std::min(count2, count5);
}

int main()
{
    return 0;
}

