//二叉树的后序遍历
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
    void postorder(TreeNode* root,vector<int>&res)
    {
        if(root==nullptr)   return; //递归出口
        postorder(root->left,res);      //遍历左子树
        postorder(root->right,res);     //遍历右子树
        res.push_back(root->val);   //访问根节点
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>res;
        postorder(root,res);
        return res;
    }
};

//2.非递归（迭代）通过先序变成“根-右-左”再反转成“左-右-根”
class Solution {
public:
    /*将先序遍历的“根->左->右”
    通过调换左子树与右子树的顺序变成“根->右->左”，
    然后再进行反转，得到“左->右->根”*/
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>res;
        stack<TreeNode*>stk;
        while(root||!stk.empty())
        {
            //不断访问右子树直到为空
            while(root)
            {
                res.push_back(root->val);
                stk.push(root);
                root=root->right;
            }
            //弹栈
            root=stk.top();
            stk.pop();
            //然后访问左子树
            root=root->left;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//3.非递归（迭代），记录父母节点的值来最后访问
/*
 这里之所以不是很赞成2的方法的原因（摘自leetcode评论区）：
 二叉树前中后序的递归版本属于easy题，而迭代版本通常是medium甚至是hard。

在做迭代版本之前，我建议大家先问问各类“遍历”算法的本质是什么？是最后输出的那一串有序的数字吗？数字的顺序是对的，遍历算法就是对的吗？

个人认为，以上问题的答案都应该是：否。“遍历”的本质是对内存的有序访问，失去了访问顺序，即便你用各种数据结构恢复了这个次序，遍历本身也显得毫无意义。常见的后序遍历写法中有一种已经出现在评论区了——它的思想也很简单，大家做过单词串翻转吗？

String in  = "it is a word"
String out = "word a is it"
这个问题有一种很优雅的写法是先reverse(in)，然后再逐词翻转——“两次反转”，最后得到的就是正确顺序。

回到二叉树后序遍历，你也可以利用这种思想，利用双向链表的addFirst，对外部次序和内含次序进行同时翻转，同样会得到一种非常”优雅”的解法，结构简单明晰，甚至还有点好背（狗头）。但是，它并没有真正实现“遍历”——仔细看会发现，该算法其实在使用一种异构的前序遍历：“中->右->左”，而非传统意义上的“中->左->右”，而这种异构也正是他的第一次反转。而第二次反转就在输出序列上。

所以本质上，这是一个“前序遍历”，而不是所谓的“后序遍历”。只有当你的各个节点以“左->右->中”的次序依次出现在迭代的loop当中时，它才是真正的后序遍历，就像官解那样。贴个我个人的版本。
 */
class Solution {
public:
    //用一个指针prev来区分节点是否已经访问过它的右子树
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>res;
        stack<TreeNode*>stk;
        TreeNode* prev=nullptr;
        while(root||!stk.empty())
        {
            //访问左子树直到为空
            while(root)
            {
                
                stk.push(root);
                root=root->left;
            }
            //弹栈
            root=stk.top();
            stk.pop();
            //右子树已经被访问过
            if(root->right==nullptr||root->right==prev)
            {
                //访问根节点，更新prev与root
                res.push_back(root->val);
                prev=root;
                root=nullptr;  //更新root为空是为了让下次循环再次弹栈
            }
            else    //右子树还未被访问
            {
                //将根节点先压栈，因为还不到访问的时机
                stk.push(root);
                //在访问其右子树
                root=root->right;
            }
        }
        return res;
    }
};