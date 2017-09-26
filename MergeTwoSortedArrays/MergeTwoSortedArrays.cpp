// MergeTwoSortedArrays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>

std::vector<int> mergeSortedArray(std::vector<int> &A, std::vector<int> &B)
{
    // write your code here
    std::vector<int> result;
    size_t ia = 0;
    size_t ib = 0;
    while (ia != A.size() && ib != B.size())
    {
        if (A[ia] < B[ib])
        {
            result.push_back(A[ia]);
            ++ia;
        }
        else
        {
            result.push_back(B[ib]);
            ++ib;
        }
    }

    if (ia < A.size())
    {
        result.insert(result.end(), A.begin() + ia, A.end());
    }
    if (ib < B.size())
    {
        result.insert(result.end(), B.begin() + ib, B.end());
    }
    return result;
}

int main()
{
    return 0;
}
