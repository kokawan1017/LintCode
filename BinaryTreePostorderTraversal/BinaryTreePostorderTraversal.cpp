// BinaryTreePostorderTraversal.cpp : 定义控制台应用程序的入口点。
//
//http://www.lintcode.com/zh-cn/problem/binary-tree-postorder-traversal/

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

void postorderTraversal(TreeNode* root, std::vector<int>& results)
{
    if (root)
    {
        postorderTraversal(root->left, results);
        postorderTraversal(root->right, results);
        results.push_back(root->val);
    }
}

std::vector<int> postorderTraversal(TreeNode *root)
{
    // write your code here
    std::vector<int> results;
    postorderTraversal(root, results);
    return results;
}


int main()
{
    return 0;
}
