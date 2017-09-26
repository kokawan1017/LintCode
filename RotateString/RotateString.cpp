// RotateString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>

void rotateString(std::string &str, int offset)
{
    // write your code here
    offset %= static_cast<int>(str.length());


}

int main()
{
    return 0;
}
