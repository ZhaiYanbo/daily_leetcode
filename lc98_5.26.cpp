//验证二叉搜索树
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
    //得到左子树的最大元素
    int getLeftMax(TreeNode* root)
    {
        TreeNode* temp=root->left;
        while(temp->right)
            temp=temp->right;
        return temp->val;
    }
    //得到右子树的最小元素
    int getRightMin(TreeNode* root)
    {
        TreeNode* temp=root->right;
        while(temp->left)
            temp=temp->left;
        return temp->val;
    }

    bool isValidBST(TreeNode* root) 
    {
        if(!root)   return true;
        else if(root->left&&getLeftMax(root)>=root->val)   return false;
        else if(root->right&&getRightMin(root)<=root->val) return false;
        return (isValidBST(root->left)&&isValidBST(root->right));
    }
};