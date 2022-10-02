//复制带随机指针的链表

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


/**
 * @brief 深拷贝，使用哈希表与递归
 *      哈希表保证每个节点只创建一次
 *      O（n），O（n）
 */
class Solution {
public:
    unordered_map<Node*,Node*>cachedNode;

    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        //没有就递归创建
        if(!cachedNode.count(head)) {
            Node* newhead = new Node(head->val);
            cachedNode[head] = newhead;
            newhead->next = copyRandomList(head->next);
            newhead->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};