// PartitionArray.cpp : 定义控制台应用程序的入口点。
//
// http://www.lintcode.com/zh-cn/problem/partition-array/

#include "stdafx.h"
#include <vector>

int partitionArray(std::vector<int> &nums, int k)
{
    if (nums.empty())
    {
        return 0;
    }

    // write your code here
    size_t firstLarger = 0;
    for (size_t i = 0; i != nums.size(); ++i)
    {
        firstLarger = i;
        if (nums[i] < k)
        {

        }
        else
        {

        }
    }
}

int main()
{
    return 0;
}
