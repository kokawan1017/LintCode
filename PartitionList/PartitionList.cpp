// PartitionList.cpp : 定义控制台应用程序的入口点。
//
// http://www.lintcode.com/zh-cn/problem/partition-list/

#include "stdafx.h"

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

ListNode * partition(ListNode * head, int x)
{
    ListNode* smallers = NULL;
    ListNode* smallerTail = NULL;
    ListNode* largers = NULL;
    ListNode* largerTail = NULL;

    for (ListNode* node = head; node != NULL; )
    {
        if (node->val < x)
        {
            if (smallers != NULL)
            {
                smallerTail->next = node;
                node = node->next;
                smallerTail = smallerTail->next;
                smallerTail->next = NULL;
            }
            else
            {
                smallers = node;
                node = node->next;
                smallers->next = NULL;
                smallerTail = smallers;
            }
        }
        else
        {
            if (largers != NULL)
            {
                largerTail->next = node;
                node = node->next;
                largerTail = largerTail->next;
                largerTail->next = NULL;
            }
            else
            {
                largers = node;
                node = node->next;
                largers->next = NULL;
                largerTail = largers;
            }
        }
    }

    if (smallerTail != NULL)
    {
        smallerTail->next = largers;
        return smallers;
    }
    else
    {
        return largers;
    }
}

int main()
{
    return 0;
}
