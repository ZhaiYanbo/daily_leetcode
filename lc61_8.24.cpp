//旋转链表

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)   return nullptr;

        ListNode* last = head;
        int len = 1;
        while(last->next!=nullptr) {
            last = last->next;
            len++;
        }

         k %= len;
        if(!k)  return head;
        ListNode* broken = head;
        int i = len-k-1;
        while(i--) broken = broken->next;
        ListNode* newhead = broken->next;
        last->next = head;
        broken->next = nullptr;
        return newhead; 
    }
};