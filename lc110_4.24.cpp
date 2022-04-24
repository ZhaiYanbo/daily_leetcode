//判断树是否为平衡二叉树（即每个节点的左子树与右子树高度差的绝对值不超过1）
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
    //获得二叉树的高度
    int getHeight(TreeNode* node)
    {
        if(!node)   return 0;
        return max_2(getHeight(node->left),getHeight(node->right))+1;
    }

    
    //是否是平衡二叉树
    bool isBalanced(TreeNode* root) 
    {
        if(!root)   return true;
        if(abs(getHeight(root->left)-getHeight(root->right))>1)
            return false;
        return  isBalanced(root->left)&&isBalanced(root->right);
    }
};

