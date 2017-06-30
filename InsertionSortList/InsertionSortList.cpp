// InsertionSortList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <sstream>

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

    // 参考代码
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

    /**
    * @param head: The first node of linked list.
    * @return: The head of linked list.
    */
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head)
        {
            return NULL;
        }

        ListNode* newHead = new ListNode(head->val);

        // 从第2个元素开始遍历
        for (ListNode* node = head->next; node != NULL; node = node->next)
        {
            if (node->val < newHead->val)
            {
                // 放前面
            }
            else
            {
                // 放后面
            }
        }
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

int main()
{
    int aaa[5] = { 4,5,1,3,2 };
    Solution s;
    s.insert_sort(aaa, 5);
    return 0;
}

