//环形链表

/**
 * @brief 快慢指针，当指针有重合的时候则说明存在环，否则不存在
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //快慢指针
    bool hasCycle(ListNode *head) {
        if(head==nullptr)   return false;
        ListNode* fast = head;
        ListNode* low  = head;
        while(fast&&fast->next) {
            fast = fast->next->next;
            low = low ->next;
            if(fast==low)   return true;
        }
        return false;
    }
};