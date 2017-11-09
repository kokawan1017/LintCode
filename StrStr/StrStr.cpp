// StrStr.cpp : 定义控制台应用程序的入口点。
//
//http://www.lintcode.com/en/problem/strstr/

#include "stdafx.h"
#include <iostream>
#include <cassert>

int strStr(const char *source, const char *target)
{
    // write your code here
    if (NULL == source || NULL == target)
    {
        return -1;
    }

    bool found = true;
    for (int i = 0; ; ++i)
    {
        found = true;
        for (int j = 0; ; ++j)
        {
            if ('\0' != target[j] && '\0' != source[i + j] && source[i + j] != target[j])
            {
                found = false;
                break;
            }

            if ('\0' == target[j])
            {
                break;
            }

            if ('\0' == source[i + j])
            {
                return -1;
            }
        }

        if (found)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    char* s1 = "abcdabcdefg";
    char* t1 = "bcd";
    std::cout << strStr(s1, t1) << std::endl;

    char* s2 = "source";
    char* t2 = "target";
    std::cout << strStr(s2, t2) << std::endl;

    char* s3 = "";
    char* t3 = "";
    std::cout << strStr(s3, t3) << std::endl;

    return 0;
}
