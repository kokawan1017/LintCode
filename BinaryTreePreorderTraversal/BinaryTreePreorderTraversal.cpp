// BinaryTreePreorderTraversal.cpp : �������̨Ӧ�ó������ڵ㡣
//
// http://www.lintcode.com/zh-cn/problem/binary-tree-preorder-traversal/

#include "stdafx.h"
#include <vector>

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
};

void preorderTraversal(TreeNode* root, std::vector<int>& results)
{
    if (root)
    {
        results.push_back(root->val);
        preorderTraversal(root->left, results);
        preorderTraversal(root->right, results);
    }
}

std::vector<int> preorderTraversal(TreeNode *root)
{
    // write your code here
    std::vector<int> results;
    preorderTraversal(root, results);
    return results;
}

int main()
{
    return 0;
}
