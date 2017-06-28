// Fibonacci.cpp : 定义控制台应用程序的入口点。
//
/*
http://www.lintcode.com/en/problem/fibonacci/

Find the Nth number in Fibonacci sequence.

A Fibonacci sequence is defined as follow:

The first two numbers are 0 and 1.
The i th number is the sum of i-1 th number and i-2 th number.
The first ten numbers in Fibonacci sequence is:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...

Notice

The Nth fibonacci number won't exceed the max value of signed 32-bit integer in the test cases.

Example
Given 1, return 0

Given 2, return 1

Given 10, return 34
*/

#include "stdafx.h"
#include <iostream>

/*
斐波那契数列: 迭代解法
*/
int fibonacci(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    int a = 0;
    int b = 1;
    for (int i = 3; i <= n; ++i)
    {
        int tmp = b;
        b = a + b;
        a = tmp;
    }

    return b;
}

int main()
{
    std::cout << fibonacci(10) << std::endl;

    std::cout << fibonacci(41) << std::endl;
    return 0;
}

