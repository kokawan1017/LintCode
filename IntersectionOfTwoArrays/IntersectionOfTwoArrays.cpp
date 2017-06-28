// IntersectionOfTwoArrays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>

bool contains(const std::vector<int>& numbers, int target)
{
    for (size_t i = 0; i != numbers.size(); ++i)
    {
        if (target == numbers[i])
        {
            return true;
        }
    }

    return false;
}

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
{
    // Write your code here
    std::vector<int> resultVec;

    for (size_t i = 0; i != nums1.size(); ++i)
    {
        if (contains(nums2, nums1[i]))
        {
            if (!contains(resultVec, nums1[i]))
            {
                resultVec.push_back(nums1[i]);
            }
        }
    }

    return resultVec;
}

int main()
{
    return 0;
}

