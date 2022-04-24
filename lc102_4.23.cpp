//二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*>q;  //辅助队列
        vector<vector<int> >res;    //存放结果的数组
        if(root)    q.push(root);
        while(!q.empty())
        {
            vector<int>smallres;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                root=q.front();
                q.pop();
                smallres.push_back(root->val);
                if(root->left)  q.push(root->left);
                if(root->right) q.push(root->right);
            }
            res.push_back(smallres);
        }
        return res;
    }
};

//2.层序遍历
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        queue<TreeNode*>myque;    //辅助队列
        if(!root)   return 0;
        myque.push(root);
        int res=0;
        while(!myque.empty())
        {
            int q_size=myque.size();
            for(int i=0;i<q_size;i++)
            {
                TreeNode* node=myque.front();
                myque.pop();
                if(node->left)  myque.push(node->left);
                if(node->right)  myque.push(node->right);
            }
            res++;
            
        }
        return res;
    }
};