//二叉树的先序遍历

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
    void preorder(TreeNode* root,vector<int>& res)
    {
        //递归出口
        if(root==nullptr) return;
        res.push_back(root->val);   //访问根节点
        preorder(root->left,res);   //遍历左子树
        preorder(root->right,res);  //遍历右子树
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {   
        vector<int>res;
        preorder(root,res);
        return res;
    }
};

//2.非递归（迭代）
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int>res;
        //if(!root)   return res;
        
        stack<TreeNode*>stk;
        while(root||!stk.empty())
        {
            //一直到左孩子为空
            while(root)
            {
                /*先序遍历的访问在这里*/
                res.push_back(root->val);

                stk.push(root);
                root=root->left;
            }
            //弹栈并访问根节点
            root=stk.top();
            stk.pop();
            /*
            中序遍历的访问在这里
            res.push_back(root->val);
            */
            //访问其右子树
            root=root->right;
        }
        return res;
    }
    
};