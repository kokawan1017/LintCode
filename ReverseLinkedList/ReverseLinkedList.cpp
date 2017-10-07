// ReverseLinkedList.cpp : 定义控制台应用程序的入口点。
//

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

ListNode * reverseBetween(ListNode * head, int m, int n)
{

}

int main()
{
    return 0;
}
