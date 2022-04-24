//翻转二叉树，返回根节点
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
//1.前序递归
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root==nullptr)   return root;
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

//2.前序迭代
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
class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        stack<TreeNode*>stk;
        TreeNode* node=root;
        while(node||!stk.empty())
        {
            //一直访问到左子树为空
            while(node)
            {
                swap(node->left,node->right);
                stk.push(node);
                node=node->left;
            }
            //弹栈
            node=stk.top();
            stk.pop();
            //访问其右子树
            node=node->right;
        }
        return root;
    }
};
