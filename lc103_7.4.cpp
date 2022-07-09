//二叉树的锯齿形层序遍历
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

//1.按照层序遍历的方法，在偶数层反转即可
class Solution {
public:
    //队列置空
    void clear(queue<TreeNode*>& q) {
        queue<TreeNode*> empty;
        swap(empty, q);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        //特判
        if(!root)   return {};
        vector<vector <int>>res;
        queue<TreeNode*>q1;
        q1.push(root);
        res.push_back({root->val});
        int i=1;
        while(!q1.empty())
        {
            queue<TreeNode*>q2(q1);    //q1赋值给q2
            clear(q1);   //q1置空
            vector<int>temp;
            while(!q2.empty())
            {
                TreeNode* cur=q2.front();
                q2.pop();
                if(cur->left)
                {
                    q1.push(cur->left);
                    temp.push_back(cur->left->val);
                }   
                if(cur->right)
                {
                    q1.push(cur->right);
                    temp.push_back(cur->right->val);
                }
            }
            i++;
            if(!temp.empty())
            {
                //偶数层反转即可
                if(i%2==0)  reverse(temp.begin(),temp.end());
                res.push_back(temp);
            }
        }
        return res;
    }
};

//2.广度优先双端队列
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        //特判
        if(!root)   return {};

        bool isleft=true;   //表示遍历方向，每次新遍历一层取反即可
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int len=q.size();
            deque<int>dq; //双端队列
            for(int i=0;i<len;i++)
            {
                auto temp=q.front();
                q.pop();
                //从左到右的时候每次从队尾插入
                if(isleft)
                {
                    dq.push_back(temp->val);
                }
                //从左到右的时候每次从队头插入，这样队头到队尾就是从右到左
                else
                {
                    dq.push_front(temp->val);
                }
                if(temp->left)  q.push(temp->left);
                if(temp->right)  q.push(temp->right);
            }
            res.emplace_back(vector<int>(dq.begin(),dq.end()));
            isleft=!isleft;
        }
        return res;
    }
};