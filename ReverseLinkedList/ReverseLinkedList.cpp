// ReverseLinkedList.cpp : 定义控制台应用程序的入口点。
//
// http://www.lintcode.com/zh-cn/problem/reverse-linked-list/
// http://www.lintcode.com/zh-cn/problem/reverse-linked-list-ii/

#include "stdafx.h"
#include <iostream>

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }

    ListNode(int val, ListNode* next)
    {
        this->val = val;
        this->next = next;
    }
};

ListNode* reverse(ListNode* head)
{
    ListNode* newHead = NULL;
    for (ListNode* node = head; node != NULL;)
    {
        ListNode* pn = node->next;

        node->next = newHead;

        newHead = node;

        node = pn;
    }
    return newHead;
}

// [m, n], 1 <= m <= n <= 表长
ListNode * reverseBetween(ListNode * head, int m, int n)
{
    // 分离出[m, n]的前面部分
    ListNode* parentFirst = NULL;
    for (int i = 1; i < m; ++i)
    {
        if (parentFirst)
        {
            parentFirst = parentFirst->next;
        }
        else
        {
            parentFirst = head;
        }
    }
    ListNode* childHead = NULL;
    if (parentFirst)
    {
        childHead = parentFirst->next;
    }
    else
    {
        childHead = head;
    }

    // 分离出[m, n]的后面部分
    ListNode* childLast = childHead;
    for (int i = 0; i != n - m; i++)
    {
        childLast = childLast->next;
    }
    ListNode* parentLast = childLast->next;
    childLast->next = NULL;

    // 将子链表逆序
    childLast = childHead;
    childHead = reverse(childHead);

    // 将链表重新拼接
    if (parentFirst != NULL)
    {
        parentFirst->next = childHead;
    }
    else
    {
        head = childHead;
    }
    childLast->next = parentLast;

    return head;
}

int main()
{
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    head = reverseBetween(head, 1, 4);
    return 0;
}
