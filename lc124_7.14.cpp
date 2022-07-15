//二叉树中的最大路径和
/*类似于lc543，遍历每个节点，求通过这个节点的最大和*/

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
private:
    int res;
public:
    int myMAx(int a,int b)
    {
        return a>b?a:b;
    }

    int getPathSum(TreeNode* root)
    {
        if(!root)   return 0;
        int L=getPathSum(root->left);
        int R=getPathSum(root->right);
        return myMAx(myMAx(L>0?L:0,R>0?R:0)+root->val,0);
    }

    void traverse(TreeNode* root)
    {
        if(!root)   return;
        int cur=getPathSum(root->left)+getPathSum(root->right)+root->val;
        res=myMAx(res,cur);
        traverse(root->left);
        traverse(root->right);
    }

    int maxPathSum(TreeNode* root) 
    {
        res=root->val;
        traverse(root);
        return res;
    }
};