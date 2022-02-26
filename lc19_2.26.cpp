//删除链表的倒数第N个节点
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
    struct ListNode{
        int val;
        ListNode* next;
        ListNode():val(0),next(nullptr){}
        ListNode(int val):val(val),next(nullptr){}
        ListNode(int val,ListNode* next):val(val),next(next){}
    };
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        //创建虚拟头节点
        ListNode* dummyHead=new ListNode();
        dummyHead->next=head;
        //
        ListNode* fast=dummyHead;
        ListNode* slow=dummyHead;
        //因为fast要移动n+1次，所以先将n++
        n++;
        while(fast!=nullptr&&n--)
            fast=fast->next;
        while(fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        //删除slow指向的节点的下一个节点
        /*
        ListNode* temp=slow->next;
        if(temp==head)  return head->next;
        slow->next=slow->next->next;
        delete temp;
        
        return head;
        */
       //上面代码优化版本
       ListNode* temp=slow->next;
       slow->next=slow->next->next;
       delete temp;
       return dummyHead->next;
    }
};