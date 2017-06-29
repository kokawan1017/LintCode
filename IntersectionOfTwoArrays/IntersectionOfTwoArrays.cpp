// IntersectionOfTwoArrays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
{
    // Write your code here
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    std::vector<int> result(nums1.size() + nums2.size());

    auto it = std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), result.begin());

    result.resize(it - result.begin());

    std::sort(result.begin(), result.end());
    auto it2 = std::unique(result.begin(), result.end());
    result.resize(it2 - result.begin());
    return result;
}

int main()
{
    return 0;
}

