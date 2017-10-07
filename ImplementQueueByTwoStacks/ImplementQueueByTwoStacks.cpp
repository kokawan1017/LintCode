// ImplementQueueByTwoStacks.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>

class MyQueue
{
public:
    std::stack<int> stack1;
    std::stack<int> stack2;
    bool isSwaped;

    MyQueue()
    {
        // do intialization if necessary
        isSwaped = false;
    }

    /*
    * @param element: An integer
    * @return: nothing
    */
    void push(int element)
    {
        // write your code here
        if (isSwaped)
        {
            dump(stack2, stack1);
            isSwaped = false;
        }

        stack1.push(element);
    }

    /*
    * @return: An integer
    */
    int pop()
    {
        // write your code here
        if (!isSwaped)
        {
            dump(stack1, stack2);
            isSwaped = true;
        }

        int n = stack2.top();
        stack2.pop();
        return n;
    }

    /*
    * @return: An integer
    */
    int top()
    {
        // write your code here
        if (!isSwaped)
        {
            dump(stack1, stack2);
            isSwaped = true;
        }

        return stack2.top();
    }

    void dump(std::stack<int>& source, std::stack<int>& target)
    {
        while (!source.empty())
        {
            target.push(source.top());
            source.pop();
        }
    }
};

int main()
{
    return 0;
}
