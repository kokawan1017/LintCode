// RotateList.cpp : 定义控制台应用程序的入口点。
//
//http://www.lintcode.com/en/problem/rotate-list/

#include "stdafx.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

ListNode* rotateRight(ListNode* head, int k)
{
    // write your code here
    if (NULL == head || NULL == head->next)
    {
        return head;
    }

    ListNode* tail = head;
    int n = 0;
    while (true)
    {
        ++n;
        if (tail->next == NULL)
        {
            break;
        }
        tail = tail->next;
    }

    tail->next = head;

    k %= n;
    n -= k;
    for (int i = 0; i != n; ++i)
    {
        head = head->next;
        tail = tail->next;
    }

    tail->next = NULL;
    return head;
}

int main()
{
    return 0;
}
