// MinStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>

class MinStack
{
    std::vector<int> data;
    int minVal;

public:
    /*
    * @param a: An integer
    */
    MinStack(int a)
    {
        // do intialization if necessary
        minVal = a;
        data.push_back(a);
    }

    /*
    * @param number: An integer
    * @return: nothing
    */
    void push(int number)
    {
        // write your code here
        data.push_back(number);
        if (number < minVal)
        {
            minVal = number;
        }
    }

    /*
    * @param a: An integer
    * @return: An integer
    */
    int pop(int a)
    {
        // write your code here

    }

    /*
    * @param a: An integer
    * @return: An integer
    */
    int min(int a)
    {
        // write your code here
        data.back();
        return minVal;
    }
};

int main()
{
    return 0;
}
