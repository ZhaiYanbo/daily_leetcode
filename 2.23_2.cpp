//移除链表元素
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

//1.头节点单独处理
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        //处理头节点
        while(head!=NULL&&head->val==val)
        {
            ListNode* temp=head;
            head=head->next;
            delete temp;
        }
        //处理非头节点的节点
        ListNode* cur=head;
        while(cur!=NULL&&cur->next!=NULL)
        {
            if(cur->next->val==val)
            {
                ListNode* temp=cur->next;
                cur->next=cur->next->next;
                delete temp;
            }
            else
                cur=cur->next;
        }
        return head;
    }
};

//2.设置虚拟头节点，统一处理
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //设置虚拟头节点
        ListNode* dummyNode=new ListNode(0);
        dummyNode->next=head;
        ListNode* cur=dummyNode;
        while(cur!=NULL&&cur->next!=NULL)
        {
            if(cur->next->val==val)
            {
                ListNode* temp=cur->next;
                cur->next=cur->next->next;
                delete temp;
            }
            else
                cur=cur->next;
        }
        //返回dummy->next
        //在这之前，把dummy释放掉
        head=dummyNode->next;
        ListNode* temp=dummyNode;
        delete temp;
        return head;
    }
};