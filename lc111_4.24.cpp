//二叉树的最小深度
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
//1.层序遍历
class Solution {
public:
    bool isleaf(TreeNode* node)
    {
        return  (!node->left&&!node->right);
    }
    int minDepth(TreeNode* root) 
    {
        //层序遍历求最小深度
        if(!root)   return 0;
        queue<TreeNode*>myq;
        myq.push(root);
        int dep=0;
        while(!myq.empty())
        {
            int q_size=myq.size();
            for(int i=0;i<q_size;i++)
            {
                TreeNode* node=myq.front();
                myq.pop();
                //是叶子节点，直接输入，程序结束
                if(isleaf(node))    return dep+1;
                if(node->left)  myq.push(node->left);
                if(node->right) myq.push(node->right);
            }
            dep++;
        }
        return 0;
    }
};

//2.递归
class Solution {
public:
    int min_2(int a,int b)
    {
        return a<b?a:b;
    }
    int minDepth(TreeNode* root) 
    {
        if(!root)   return 0;   //为空返回0
        if(root->left==nullptr&&root->right!=nullptr)   //左子树为空，右子树不为空
            return minDepth(root->right)+1;
        if(root->left!=nullptr&&root->right==nullptr)   //左子树不为空，右子树为空
            return minDepth(root->left)+1;
        //左右子树都不为空
        return min_2(minDepth(root->left),minDepth(root->right))+1;
    }
};