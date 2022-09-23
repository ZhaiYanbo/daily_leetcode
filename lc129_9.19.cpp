//求根节点到叶子节点数字之和


/**
 * @brief DFS
 * 
 */
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
    vector<string>records;
    int res = 0;
public:
    void dfs(TreeNode* root,string cur) {
        if(!root->left && !root->right) {
            cur += char('0'+root->val);
            records.push_back(cur);
            return ;
        }
        if(root->left)  dfs(root->left,cur+char('0'+root->val));
        if(root->right) dfs(root->right,cur+char('0'+root->val));
    }

    int sumNumbers(TreeNode* root) {
        if(!root)   return 0;
        dfs(root,"");
        for(string s:records)
            res += stoi(s);

        return res;
    }
};