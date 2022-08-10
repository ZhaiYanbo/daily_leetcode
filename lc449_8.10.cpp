//序列化和反序列化二叉搜索树

//1.与297题解法相同，当作普通二叉树来处理
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    //Preorder traverse a tree to get a string
    void preTraverse(TreeNode* root,string& res)
    {
        if(!root)
        {
            res += "NULL,";
            return ;
        }
        res += to_string(root->val)+',';
        preTraverse(root->left,res);
        preTraverse(root->right,res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string res = "";
        preTraverse(root,res);
        return res;
    }

    //Build a tree by list
    TreeNode* build(list<string>& nums)
    {
        if(nums.front()=="NULL")
        {
            nums.erase(nums.begin());
            return nullptr;
        }
        TreeNode* root =new TreeNode(stoi(nums.front()));
        nums.erase(nums.begin());
        root->left = build(nums);
        root->right = build(nums);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        string str;
        list<string> nums;
        for(char c:data)
        {
            if(c==',')
            {
                nums.push_back(str);
                str.clear();
            }
            else
            {
                str.push_back(c);
            }
        }
        return build(nums);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

//2.没有二分优化，与1类似，只是细分成了更多的函数
//O(n^2)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Push a tree to a vector
    void pushToVector(TreeNode* root,vector<int>&nums)
    {
        if(!root)   return ;
        nums.push_back(root->val);
        pushToVector(root->left,nums);
        pushToVector(root->right,nums);
    }

    // vector->string
    string vectorToString(vector<int>&nums)
    {
        string res = "";
        int len = nums.size();
        for(int i = 0;i< len;i++)
        {
            res += to_string(nums[i])+',';
        }
        
        return res;
    }

    //split string to a number vector(ordered)
    vector<int>splitString(string s)
    {
        string temp = "";
        vector<int>res;
        for(char c:s)
        {
            if(c==',')
            {
                res.push_back(stoi(temp));
                temp.clear();
            }
            else
            {
                temp.push_back(c);
            }
        }
        return res;
    }

    //build tree by a vector
    TreeNode* build(vector<int>&nums)
    {
        if(nums.size()==0)  return nullptr;
        TreeNode* root = new TreeNode(nums[0]);
        vector<int>leftv;
        vector<int>rightv;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[0])
                leftv.push_back(nums[i]);
            else
                rightv.push_back(nums[i]);
        }
        root->left = build(leftv);
        root->right = build(rightv);
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        vector<int>nums;
        pushToVector(root,nums);
        return vectorToString(nums);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<int>nums = splitString(data);
        return build(nums);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;


//3.利用BST有序的特性进行二分优化，O(nlogn)
