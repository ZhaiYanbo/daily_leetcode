//反转链表

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
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 //1.双指针法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)  return head;
        ListNode* cur=head->next;
        ListNode* ne=cur->next;
        head->next=nullptr;
        while(cur)
        {
            cur->next=head;
            
            head=cur;
            cur=ne;
            if(ne)
                ne=ne->next;
        }
        return head;
    }
};

//2.递归法（并未完全掌握，参考Cral边看边写）
class Solution{
    public:
    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur==nullptr)    return pre;
        ListNode* temp=cur->next;
        cur->next=pre;
        return(cur,temp);
    }
    ListNode* ListReverse(ListNode* head){
        return reverse(nullptr,head);
    }
};