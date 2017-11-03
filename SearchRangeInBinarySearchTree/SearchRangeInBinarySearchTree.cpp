// SearchRangeInBinarySearchTree.cpp : 定义控制台应用程序的入口点。
//
// http://www.lintcode.com/zh-cn/problem/search-range-in-binary-search-tree/

#include "stdafx.h"
#include <vector>
#include <algorithm>

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
};

void traverse(TreeNode* root, int k1, int k2, std::vector<int>& results)
{
    if (root)
    {
        if (root->val < k1)
        {
            traverse(root->right, k1, k2, results);
        }
        else if (root->val == k1)
        {
            results.push_back(root->val);
            traverse(root->right, k1, k2, results);
        }
        else if (k1 < root->val && root->val < k2)
        {
            traverse(root->left, k1, k2, results);
            results.push_back(root->val);
            traverse(root->right, k1, k2, results);
        }
        else if (root->val == k2)
        {
            traverse(root->left, k1, k2, results);
            results.push_back(root->val);
        }
        else // k2 < root->val
        {
            traverse(root->left, k1, k2, results);
        }
    }
}

std::vector<int> searchRange(TreeNode* root, int k1, int k2)
{
    std::vector<int> results;
    traverse(root, k1, k2, results);
    return results;
}

int main()
{
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->right = new TreeNode(22);
    searchRange(root, 10, 22);
    return 0;
}
