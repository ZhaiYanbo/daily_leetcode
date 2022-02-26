//判断链表是否有环
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int val):val(val),next(nullptr){}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        //特判
        if(head==nullptr||head->next==nullptr)  return nullptr;

        ListNode* fast=head->next->next;
        ListNode* slow=head->next;
        while(fast!=nullptr&&fast->next!=nullptr&&fast!=slow)
        {
            fast=fast->next->next;
            slow=slow->next;

        }
        if(slow!=fast)  return nullptr;
        while(head!=slow)
        {
            head=head->next;
            slow=slow->next;
        }  
        return head;

    }
};