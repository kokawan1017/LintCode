// ReversePairs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>

long long reversePairs(std::vector<int>& A)
{
    // Write your code here
    long long count = 0;
    for (size_t i = 0; i != A.size(); ++i)
    {
        for (size_t j = i + 1; j != A.size(); ++j)
        {
            if (A[i] > A[j])
            {
                ++count;
            }
        }
    }

    return count;
}

int main()
{
    std::vector<int> nums = { 2, 4, 1, 3, 5 };
    std::cout << reversePairs(nums) << std::endl;
    return 0;
}

