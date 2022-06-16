//合并两个有序链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//1.自己写的迭代算法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(!list1)  return list2;
        if(!list2)  return list1;

        ListNode* res=list1->val<=list2->val?list1:list2;
        ListNode* tail=res;
        ListNode* temp=nullptr;
        //两链表都没处理完
        while(list1&&list2)
        {
            if(list1->val<=list2->val)
            {
                temp=list1;
                list1=list1->next;               
            }
            else
            {
                temp=list2;
                list2=list2->next;
            }
            tail->next=temp;    //把较小的节点加在结果链表后面
            tail=tail->next;    //更新尾指针
            
        }
        //说明list2处理结束，将l1剩余元素跟在后面即可
        if(!list2)  tail->next=list1;
        //说明list1处理结束，将l1剩余元素跟在后面即可
        else        tail->next=list2;
        return res;
    }
};

//2.递归算法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1==NULL)    return l2;
        else if(l2==NULL)    return l1;
        else if(l1->val<l2->val)
        {
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};