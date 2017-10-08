// SortList.cpp : 定义控制台应用程序的入口点。
//

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
            newNode->next = node;
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
    // write your code here
    ListNode* newHead = NULL;
    for (ListNode* node = head; node != NULL; )
    {
        if (newHead)
        {
            // 备份下一个节点
            ListNode* next = node->next;

            // 用插入排序, 把节点加入到新的链表
            for (ListNode* pn = newHead; pn != NULL; pn = pn->next)
            {
                // 插入到pn后面
                if (pn->val < node->val)
                {
                    if (pn->next)
                    {
                        if (node->val < pn->next->val)
                        {
                            // 插入到pn后面
                        }
                    }
                    else
                    {
                        pn->next = node;
                        pn->next->next = NULL;
                    }
                }
                else
                {

                }
            }

            node = next;
        }
        else
        {
            newHead = node;
            node = node->next;
            newHead->next = NULL;
        }
    }

    return newHead;
}

int main()
{
    return 0;
}
