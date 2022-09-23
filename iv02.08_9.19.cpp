//环路检测

/**
 * @brief 给定一个链表，如果有环路，返回最后一个节点指向的那个节点(返回的那个节点)
 *        如果不存在环路，则返回空指针
 */


/**
 * @brief 使用哈希表
 *      o(n)    o(n)
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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>set;
        ListNode* p = head;
        while(p) {
            if(set.find(p) != set.end())    return p;
            set.insert(p);
            p = p->next;
        }
        return nullptr;
    }
};

/**
 * @brief 快慢指针+数学证明
 *      将空间降为O(1)
 *      O(n)    O(1)
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                ListNode* res = head;
                while(slow != res){
                    slow = slow->next;
                    res  = res->next;
                }
                return res;
            }
        }
        return nullptr;
    }
};