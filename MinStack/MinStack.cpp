// MinStack.cpp : 定义控制台应用程序的入口点。
//
// http://www.lintcode.com/zh-cn/problem/min-stack/

#include "stdafx.h"
#include <stack>

class MinStack
{
    std::stack<int> data;
    std::stack<int> mins;

public:
    /*
    * @param a: An integer
    */
    MinStack()
    {
    }
    MinStack(int a)
    {
        // do intialization if necessary
        data.push(a);
        mins.push(a);
    }

    /*
    * @param number: An integer
    * @return: nothing
    */
    void push(int number)
    {
        // write your code here
        if (mins.empty())
        {
            mins.push(number);
        }
        else
        {
            if (number <= mins.top())
            {
                mins.push(number);
            }
        }
        data.push(number);
    }

    /*
    * @param a: An integer
    * @return: An integer
    */
    int pop()
    {
        // write your code here
        int val = data.top();
        if (val == mins.top())
        {
            mins.pop();
        }
        data.pop();
        return val;
    }

    /*
    * @param a: An integer
    * @return: An integer
    */
    int min()
    {
        // write your code here
        return mins.top();
    }
};

int main()
{
    return 0;
}
