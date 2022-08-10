//二叉树的序列化与反序列化
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
    //Preorder traverse a tree to get string
    void preTraverse(TreeNode* root,string& res)
    {
        if(root==nullptr)
        {
            res += "NULL,";
            return ;
        }
        res += to_string(root->val)+',';
        preTraverse(root->left,res);
        preTraverse(root->right,res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        preTraverse(root,res);
        return res;
    }

    //Build a tree by a list
    TreeNode* build(list<string>& nums)
    {
        if(nums.front()=="NULL")
        {
            nums.erase(nums.begin());
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(nums.front()));
        nums.erase(nums.begin());

        root->left = build(nums);
        root->right = build(nums);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        list<string>nums;
        string str="";
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
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));