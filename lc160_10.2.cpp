//相交链表

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * @brief   让两指针走相同的路程，最后一定会在相交处相遇；
 *          若两指针没有相交处，则走过m+n后都为空
 *          O(m+n)
 *          O(1)
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr ||headB == nullptr)     return nullptr;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA != pB) {
            pA = pA?pA->next:headB;
            pB = pB?pB->next:headA;
        }
        return pA;
    }
};