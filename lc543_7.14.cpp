//二叉树的直径
/*一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。*/

/*Solution:对每个节点求左孩子与右孩子深度之和，维护最大值*/
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
    //递归求深度
    int depth(TreeNode* root)
    {
        if(!root)   return 0;
        int L=depth(root->left);
        int R=depth(root->right);
        return max(L,R)+1;
    }
    
    //遍历
    void traverse(TreeNode* root)
    {
        if(!root)   return;
        int cur=depth(root->left)+depth(root->right);
        if(cur>res) res=cur;
        traverse(root->left);
        traverse(root->right);
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        res=0;
        traverse(root);
        return res;
    }
};