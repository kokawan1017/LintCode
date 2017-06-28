// FirstPositionOfTarget.cpp : 定义控制台应用程序的入口点。
//
/*
二分查找法

http://www.lintcode.com/en/problem/first-position-of-target/

For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.

If the target number does not exist in the array, return -1.

Have you met this question in a real interview? Yes
Example
If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.

*/

#include "stdafx.h"
#include <iostream>
#include <vector>

// [start, end)
int search(std::vector<int>& array, int target, int start, int end)
{
    std::cout << "[ " << start << ", " << end << " )" << std::endl;

    if (start == end)
    {
        return -1;
    }

    int mid = (end - start) / 2;

    if (array[mid] == target)
    {
        while (mid != start)
        {
            --mid;
            if (array[mid] < target)
            {
                ++mid;
                break;
            }
        }
        return mid;
    }

    if (array[mid] < target)
    {
        return search(array, target, mid + 1, end);
    }
    else if (target < array[mid])
    {
        return search(array, target, start, mid);
    }

    return -1;
}

int binarySearch(std::vector<int> &array, int target)
{
    int pos = search(array, target, 0, array.size());

    return pos;
}

int main()
{
    std::vector<int> nums = { 1, 2, 3, 3, 4, 5, 10 };

    std::cout << binarySearch(nums, 3) << std::endl;

    return 0;
}

