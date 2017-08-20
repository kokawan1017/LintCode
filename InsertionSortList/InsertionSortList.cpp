// InsertionSortList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>

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

class Solution
{
public:

    // �ο�����
    void insert_sort(int* array, int n)
    {
        int j;
        for (int i = 1; i < n; i++)
        {
            int temp = array[i];
            for (j = i; j > 0 && temp < array[j - 1]; j--)
            {
                array[j] = array[j - 1];
            }
            array[j] = temp;
        }
    }

    // �������򣬽�node���뵽head�б���
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
                    // ��ǰnode����ͷ���
                    prev->next = newNode;
                    newNode->next = node;
                }
                else
                {
                    // ��ǰnode��ͷ���
                    newNode->next = node;
                    head = newNode;
                }
                return;
            }

            prev = node;
        }

        prev->next = newNode;
    }

    /**
    * @param head: The first node of linked list.
    * @return: The head of linked list.
    */
    ListNode *insertionSortList(ListNode *head)
    {
        // write your code here
        if (NULL == head)
        {
            return NULL;
        }

        ListNode* newHead = new ListNode(head->val);

        // �ӵ�2��Ԫ�ؿ�ʼ����
        for (ListNode* node = head->next; node != NULL; node = node->next)
        {
            ListNode* newNode = new ListNode(node->val);
            insertIntoList(newHead, newNode);
        }

        return newHead;
    }

    void printList(ListNode* head)
    {
        std::ostringstream buffer;
        while (head)
        {
            buffer << head->val << "->";
            head = head->next;
        }
        buffer << "NULL";
        std::cout << buffer.str() << std::endl;
    }
};

ListNode* createList(const std::vector<int>& numbers)
{
    if (numbers.empty())
    {
        return NULL;
    }

    ListNode* head = new ListNode(numbers[0]);
    ListNode* tail = head;
    for (size_t i = 1; i != numbers.size(); ++i)
    {
        ListNode* newNode = new ListNode(numbers[i]);
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

int main()
{
    int aaa[5] = { 4,5,1,3,2 };
    Solution s;
    s.insert_sort(aaa, 5);

    std::vector<int> numbers = { 1,3,2,0 };

    ListNode* head = createList(numbers);

    ListNode* newHead = s.insertionSortList(head);
    s.printList(newHead);

    std::cout << "hehe" << std::endl;

    return 0;
}

