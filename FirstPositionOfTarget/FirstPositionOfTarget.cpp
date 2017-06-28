// FirstPositionOfTarget.cpp : 定义控制台应用程序的入口点。
//
/*
二分查找法

http://www.lintcode.com/en/problem/first-position-of-target/

For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.

If the target number does not exist in the array, return -1.

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

    int mid = start + (end - start) / 2;

    if (array[mid] == target)
    {
        int pos = search(array, target, start, mid);
        if (pos == -1)
        {
            return mid;
        }

        return pos;
    }

    if (array[mid] < target)
    {
        int pos = search(array, target, mid + 1, end);
        return pos;
    }
    else if (target < array[mid])
    {
        int pos = search(array, target, start, mid);
        return pos;
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

    std::vector<int> n2 = { 2,6,8,13,15,17,17,18,19,20 };

    std::cout << binarySearch(n2, 15) << std::endl;

    std::vector<int> n3 = { 3,4,5,8,8,8,8,10,13,14 };

    std::cout << binarySearch(n3, 8) << std::endl;

    return 0;
}

