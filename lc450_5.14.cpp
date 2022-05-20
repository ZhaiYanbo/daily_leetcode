//删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        //从二叉排序树root中删除val值等于key的节点
        TreeNode* p=root;
        TreeNode* f=nullptr;
        /*下面的while循环从根开始查找val为key的节点p*/
        while(p)
        {
            if(p->val==key) break;  //找到节点，结束循环
            f=p;                    //f记录p的双亲节点
            if(p->val>key)  p=p->left;  //在左子树中寻找
            else            p=p->right; //在右子树中寻找
        }
        if(!p)  return root;    //没找到，返回原来的树
        /*考虑三种情况实现p所指子树内部的处理：*p左右子树均不空、只有左子树或者右子树、没有左子树也没有右子树*/
        TreeNode* q=p;
        if((p->left)&&(p->right))   //被删节点左右子树都不为空，则找该节点的左子树的最右孩子做替身
        {
            TreeNode* s=p->left;
            while(s->right)
            {
                q=s;        //q记录s的父节点
                s=s->right; //一直找到最右孩子
            }
            p->val=s->val;
            if(q!=p)    q->right=s->left;   //把s的左子树（可能有）作为q的右子树
            else        q->left=s->left;       //p==q说明s就是p的左孩子
            delete(s);      //删除替身节点
            return root;
        }
        else if(!(p->left))
        {
            p=p->right;
        }
        else if(!(p->right))
        {
            p=p->left;
        }
        /*将p所指的子树挂接到其双亲节点*f相应的位置*/
        if(!f)  root=p;        //被删节点为跟根节点
        else if(q==f->left) f->left=p;
        else f->right=p;
        delete q;
        return root;
    }
};