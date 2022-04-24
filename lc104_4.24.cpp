//二叉树的最大深度
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//1.递归
class Solution {
public:
    int max_2(int a,int b)
    {
        return a>b?a:b;
    }
    int maxDepth(TreeNode* root) 
    {
        if(!root)   return 0;
        if(!root->left&&!root->right)   return 1;
        return max_2(maxDepth(root->left),maxDepth(root->right))+1;

    }
};