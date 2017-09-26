// BinaryTreeSerialization.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>

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

std::string serialize(TreeNode* root)
{
    // write your code here
}

TreeNode* deserialize(std::string &data)
{
    // write your code here
}

int main()
{
    return 0;
}
