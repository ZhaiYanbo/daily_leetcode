//反转二叉树的奇数层

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
 * 
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root)   return nullptr;
        //vector<vector<int>>v;
        //bfs
        queue<TreeNode*>q;
        q.push(root);
        int cen = 1;
        while(!q.empty()) {
            vector<int>nums;
            vector<TreeNode*>record;
            while(!q.empty()) {
                TreeNode* p = q.front();
                q.pop();
                if(p->left) {
                    if(cen%2){
                        nums.push_back(p->left->val);
                        nums.push_back(p->right->val);
                    }
                    
                    record.push_back(p->left);
                    record.push_back(p->right);
                }
            }
            //if(nums.size()) v.push_back(nums);
            if(nums.size()) {
                reverse(nums.begin(),nums.end());
                for(int i = 0;i < nums.size(); i++) {
                    record[i]->val = nums[i];
                    q.push(record[i]);
                }
            } else {
                for(int i = 0;i < record.size(); i++)
                    q.push(record[i]);
            }
            
            
            cen++;
        }
        
        return root;
    }
};

/**
 * @brief 镜像DFS
 * 
 */
class Solution {
public:
    void dfs(TreeNode* a,TreeNode* b,int d) {
        if(!a)  return ;
        if(d%2) swap(a->val,b->val);
        dfs(a->left,b->right,d+1);
        dfs(a->right,b->left,d+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left,root->right,1);
        return root;
    }
};
