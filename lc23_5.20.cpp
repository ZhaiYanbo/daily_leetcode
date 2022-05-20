//合并k个有序链表
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1,ListNode* list2)
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

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        //分治的思想
        if(lists.size()==0)  return nullptr;
        if(lists.size()==1)  return lists[0];
        vector<ListNode*> left;
        vector<ListNode*> right;
        int mid=lists.size()/2;
        for(int i=0;i<mid;i++)
        {
            left.push_back(lists[i]);
        }
        for(int i=mid;i<lists.size();i++)
        {
            right.push_back(lists[i]);
        }
        return mergeTwoLists(mergeKLists(left),mergeKLists(right));
    }
};