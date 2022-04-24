//判断是否为对称二叉树
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
    bool compare(TreeNode* left,TreeNode* right)
    {
        if(left==nullptr&&right==nullptr)   return true;
        else if(left!=nullptr&&right==nullptr)   return false;
        else if(left==nullptr&&right!=nullptr)   return false;
        else if(left->val!=right->val)   return false;
        //剩下的情况为目前相等，但要递归查看是否下层相等
        return compare(left->left,right->right)&&compare(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) 
    {
        return compare(root->left,root->right);
    }
};

//2.迭代
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
    bool isSymmetric(TreeNode* root) 
    {
        queue<TreeNode*>myqueue;
        myqueue.push(root->left);
        myqueue.push(root->right);
        while(!myqueue.empty())
        {
            TreeNode* leftnode=myqueue.front();
            myqueue.pop();
            TreeNode* rightnode=myqueue.front();
            myqueue.pop();
            //左右都为空，满足条件->继续迭代比较
            if(!leftnode&&!rightnode)   continue;
            //不相等，直接打断返回false
            else if(!leftnode||!rightnode||leftnode->val!=rightnode->val)
                return false;
            myqueue.push(leftnode->left);
            myqueue.push(rightnode->right);
            myqueue.push(leftnode->right);
            myqueue.push(rightnode->left);
        }
        //队列为空，说明全部比较完
        return true;
    }
};

//3.使用栈也可以，就是把2中队列原封不动改为栈即可