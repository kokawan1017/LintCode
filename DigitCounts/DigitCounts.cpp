// DigitCounts.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int countOne(int n, int k)
{
    int count = 0;
    while (n > 0)
    {
        if (n % 10 == k)
        {
            ++count;
        }
        n /= 10;
    }
}

int digitCounts(int k, int n)
{
    // write your code here
}

int main()
{
    return 0;
}
