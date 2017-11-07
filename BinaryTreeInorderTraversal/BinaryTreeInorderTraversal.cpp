// BinaryTreeInorderTraversal.cpp : 定义控制台应用程序的入口点。
//
//http://www.lintcode.com/zh-cn/problem/binary-tree-inorder-traversal/

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

void inorderTraversal(TreeNode* root, std::vector<int>& results)
{
    if (root)
    {
        inorderTraversal(root->left, results);
        results.push_back(root->val);
        inorderTraversal(root->right, results);
    }
}

std::vector<int> inorderTraversal(TreeNode *root)
{
    // write your code here
    std::vector<int> results;
    inorderTraversal(root, results);
    return results;
}


int main()
{
    return 0;
}
