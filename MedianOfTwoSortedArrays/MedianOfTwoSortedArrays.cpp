// MedianOfTwoSortedArrays.cpp : 定义控制台应用程序的入口点。
//
//http://www.lintcode.com/zh-cn/problem/median-of-two-sorted-arrays/

#include "stdafx.h"
#include <vector>

typedef std::vector<int> IntVector;

IntVector::iterator bFind(IntVector::iterator first, IntVector::iterator last, int val)
{
    if (first == last)
    {
        return last;
    }

    if (*first == val)
    {
        return first;
    }

    int distance = last - first;
    if (val < *(first + distance / 2))
    {

    }
    else if ()
}

double findMedianSortedArrays(std::vector<int> &A, std::vector<int> &B)
{
    // write your code here
}

int main()
{
    return 0;
}
