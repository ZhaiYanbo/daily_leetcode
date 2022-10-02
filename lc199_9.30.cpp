//二叉树的右视图

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

/**
 * @brief BFS
 *          O(n)
 *          O(n)
 */
class Solution {
public:
    //BFS
    vector<int> rightSideView(TreeNode* root) {
        if(!root)   return {};

        vector<int>res;
        queue<TreeNode*>q;
        q.push(root);

        while(q.size()) {
            int len = q.size();
            for(int i = 0; i < len; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)      q.push(temp->left);
                if(temp->right)     q.push(temp->right);
                if(i == len-1)      res.push_back(temp->val);
            }
        }

        return res;
    }
};

/**
 * @brief BFS:带着depth深度BFS
 *          按照根右左的顺序，深度第一次出现时，说明为最右边，加入结果数组即可
 *          O(n)
 *          O(n)
 */
class Solution {
public:
    vector<int>res;
    void dfs(TreeNode* root,int depth) {
        if(!root)   return ;
        if(depth == res.size()) res.push_back(root->val);
        dfs(root->right,depth+1);
        dfs(root->left,depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};