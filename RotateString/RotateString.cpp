// RotateString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>

void rotateString(std::string &str, int offset)
{
    // write your code here
    if (str.empty())
    {
        return;
    }

    offset %= static_cast<int>(str.length());

    for (int i = 0; i != offset; ++i)
    {
        rotateOneChar(str);
    }
}

void rotateOneChar(std::string& str)
{
    char last = str.back();
    for (size_t i = str.length() - 1; i > 0; --i)
    {
        str[i] = str[i - 1];
    }
    str[0] = last;
}

int main()
{
    return 0;
}
