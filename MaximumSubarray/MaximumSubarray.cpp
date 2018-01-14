// MaximumSubarray.cpp : 定义控制台应用程序的入口点。
//
/*
http://www.lintcode.com/zh-cn/problem/maximum-subarray/
http://www.lintcode.com/zh-cn/problem/maximum-subarray-ii/
http://www.lintcode.com/zh-cn/problem/maximum-subarray-iii/
*/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <climits>

int max2(int a, int b)
{
    return a < b ? b : a;
}

int max3(int a, int b, int c)
{
    return max2(a, max2(b, c));
}

int sum(const std::vector<int> &nums, size_t first, size_t last)
{
    int s = 0;
    while (first < last)
    {
        s += nums[first];
        ++first;
    }
    return s;
}

int maxSubArrayImpl(std::vector<int> &nums, size_t first, size_t last)
{
    if (last - first == 1)
    {
        return nums[first];
    }

    int sumSelf = sum(nums, first, last);
    int maxLeft = maxSubArrayImpl(nums, first, last - 1);
    int maxRight = maxSubArrayImpl(nums, first + 1, last);
    return max3(sumSelf, maxLeft, maxRight);
}

// 最大子数组
int maxSubArray(std::vector<int> &nums)
{
    return maxSubArrayImpl(nums, 0, nums.size());
}

int maxsub_1(std::vector<int>& nums)
{
    int maxSoFar = INT_MIN;
    size_t n = nums.size();
    for (size_t i = 0; i != n; ++i)
    {
        int sum = 0;
        for (size_t j = i; j < n; ++j)
        {
            sum += nums[j];
            maxSoFar = max2(maxSoFar, sum);
        }
    }

    return maxSoFar;
}

// 最大子数组2
int maxTwoSubArrays(std::vector<int> &nums)
{
    // write your code here
    return 0;
}

// 最大子数组3
int maxSubArray(std::vector<int> &nums, int k)
{
    // write your code here
    return 0;
}

int main()
{
    std::vector<int> nums = { -2,2,-3,4,-1,2,1,-5,3 };
    std::cout << maxSubArray(nums) << std::endl;

    //std::vector<int> nums2 = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-15,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
    std::vector<int> nums2 = { 1,1,1,1,1,1,1,1,1,1 };
    std::cout << maxsub_1(nums2) << std::endl;
    return 0;
}
