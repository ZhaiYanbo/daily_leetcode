//二叉树的中序遍历
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
    void inorder(TreeNode* root,vector<int>& res)
    {
        if(root==nullptr)   return; //递归终点
        inorder(root->left,res);    //遍历左子树
        res.push_back(root->val);   //访问根节点
        inorder(root->right,res);   //遍历右子树
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>res;
        inorder(root,res);
        return res;
    }
};

//2.非递归（迭代）
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>res;
        stack<TreeNode*>stk;
        while(root||!stk.empty())
        {
            //一直迭代到左子树为空
            while(root)
            {
                stk.push(root);
                root=root->left;
            }
            //弹栈，然后访问根
            root=stk.top();
            stk.pop();
            res.push_back(root->val);
            //访问右子树
            root=root->right;
        }
        return res;
    }
};