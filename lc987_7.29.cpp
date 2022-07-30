//二叉树的垂序遍历

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
    map<int,multiset<int>>node;
    void helper(TreeNode* root,int x,int y)
    {
        if(!root)   return ;
        node[x].insert(y*10000+root->val);
        helper(root->left,x-1,y+1);
        helper(root->right,x+1,y+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>>res;

        helper(root,0,0);
        for(auto it:node)
        {
            vector<int>temp;
            for(auto iter:it.second)
                temp.emplace_back(iter%10000);
            res.emplace_back(temp);
        }

        return res;
    }
};