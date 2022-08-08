//二叉树的最近公共祖先

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool find(TreeNode* root,TreeNode* target)
    {
        if(root==nullptr)   return false;
        if(root->val==target->val)  return true;
        return find(root->left,target)||find(root->right,target);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        //if(root==nullptr)   return nullptr;
        //其中p或q为根节点，再由题面所说pq均存在于给定的二叉树，所以最后的公共祖先一定是root
        if(root->val==p->val||root->val==q->val)    return root;
        //p、q均在root的左子树中，在左子树中寻找
        if(find(root->left,p)&&find(root->left,q))  return lowestCommonAncestor(root->left,p,q);
        //p、q均在root的右子树中，在右子树中寻找
        if(find(root->right,p)&&find(root->right,q))  return lowestCommonAncestor(root->right,p,q);
        //一个在左子树，一个在右子树
        return root;
    }


};