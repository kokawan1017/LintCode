// SortList.cpp : 定义控制台应用程序的入口点。
//
// http://www.lintcode.com/zh-cn/problem/sort-list/

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

// 按照升序，将node插入到head列表中
void insertIntoList(ListNode*& head, ListNode* newNode)
{
    newNode->next = NULL;
    if (NULL == head)
    {
        head = newNode;
        return;
    }

    ListNode* node = head;
    ListNode* prev = NULL;
    for (; node != NULL; node = node->next)
    {
        if (newNode->val < node->val)
        {
            if (prev)
            {
                // 当前node不是头结点
                prev->next = newNode;
                newNode->next = node;
            }
            else
            {
                // 当前node是头结点
                newNode->next = node;
                head = newNode;
            }
            return;
        }

        prev = node;
    }

    prev->next = newNode;
}

ListNode * sortList(ListNode * head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode* newHead = head;
    head = head->next;
    newHead->next = NULL;
    for (ListNode* node = head; node != NULL;)
    {
        ListNode* next = node->next;
        insertIntoList(newHead, node);
        node = next;
    }

    return newHead;
}

ListNode* sortList_select(ListNode * head)
{
    ListNode* small = NULL;
    int tmp = 0;
    for (ListNode* i = head; i != NULL; i = i->next)
    {
        small = i;
        for (ListNode* j = i->next; j != NULL; j = j->next)
        {
            if (j->val < small->val)
            {
                small = j;
            }
        }

        if (small != i)
        {
            tmp = small->val;
            small->val = i->val;
            i->val = tmp;
        }
    }

    return head;
}

ListNode* sortList_quick(ListNode* head)
{

}


int main()
{
    ListNode* head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(-1);

    head = sortList_select(head);

    return 0;
}
