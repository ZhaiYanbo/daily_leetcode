//根据二叉树创建字符串
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
class Solution {

public:
    void preTraverse(TreeNode* root,string& res)
    {
        res += to_string(root->val);
        
        if(!root->left&&!root->right)   return;

        res += '(';
        if(root->left)
        {
            preTraverse(root->left,res);
        }
        res += ')';

        if(root->right)
        {
            res += '(';
            preTraverse(root->right,res);
            res += ')';
        }

    }

    string tree2str(TreeNode* root) 
    {
        string res = "";
        preTraverse(root,res);
        return res;
    }
};