//排序链表

#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeSortedList(ListNode* l1,ListNode* l2)
    {   
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1; 
        ListNode* res = nullptr;
        if(l1->val<l2->val)
        {
            res = l1;
            l1 = l1->next;
        }
        else
        {
            res = l2;
            l2 = l2->next;
        }
        ListNode* cur=res;
        //直到一个链表处理结束
        while(l1!=nullptr&&l2!=nullptr)
        {
            if(l1->val > l2->val)
            {
                cur->next = l2;
                l2 = l2->next;
            }
            else
            {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
            cur->next = nullptr;
        }
        //l2处理结束
        if(l1)  cur->next = l1;
        //l1处理结束
        else  cur->next = l2;

        return res;
    }
    
    ListNode* sortListRecursion(ListNode* head)
    {
        if(head==nullptr||head->next==nullptr)  return head;

        ListNode* fast = head;
        ListNode* low  = head;
        /**
            通过快慢指针的方式获得链表的中间节点的指针，
            即fast走两步，low走一步，直至fast为空
            这里之所以先让fast走两步再同时开始走，
            是因为需要将low放到中间元素的前驱位置，需要断链，
            再移至中间位置        
        */
        fast = fast->next->next;
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            low = low->next;
            fast = fast->next->next;
        }
        ListNode* temp = low->next;
        low->next = nullptr;
        low = temp;
        
        ListNode* l1 = sortListRecursion(head);
        ListNode* l2 = sortListRecursion(low);
        return mergeSortedList(l1,l2);
    }

    ListNode* sortList(ListNode* head) 
    {
        return sortListRecursion(head);
    }
};

int main()
{
    ListNode* n1 =new ListNode(4);
    ListNode* n2 =new ListNode(2);
    ListNode* n3 =new ListNode(1);
    ListNode* n4 =new ListNode(3);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    ListNode* head = n1;

    Solution s;
    ListNode* ans = s.sortList(head);

    return 0;
}