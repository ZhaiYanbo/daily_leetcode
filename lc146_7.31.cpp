//LRU缓存
#include<unordered_map>
#include<iostream>
using namespace std;

/**
 * 
 * @brief 哈希表+双向链表实现LRU
 * 这里之所以用ListNode1是因为，
 * 用ListNode在力扣平台过不了，疯狂报重复定义的错误
 * 后来查了一下，发现是原来内置已经定义了"ListNode",
 * 所以更改个变量名即可
 */
typedef struct ListNode1
{
    int key;
    int val;
    struct ListNode1* next;
    struct ListNode1* pre;
    ListNode1(int __key,int __val):key(__key),val(__val),next(nullptr),pre(nullptr){}
}ListNode1,*LinkedList;


class LRUCache {
public:
    LinkedList head,rear;
    unordered_map<int,ListNode1*>hash;
    int cap;
    int size;
    LRUCache(int capacity) 
    {
        head = new ListNode1(0,0);
        rear = new ListNode1(0,0);
        size = 0;
        cap = capacity;
        head->next = rear;
        rear->pre = head;
    }
    
    int get(int key) 
    {
        if(hash.find(key)==hash.end())
        {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        LinkedList target = hash[key];
        moveToHead(target);
        return target->val;
    }
    
    void put(int key, int value) 
    {
        //找到了，更新value值，并移到链表头部
        if(hash.find(key)!=hash.end())
        {
            LinkedList target = hash[key];
            target->val = value;
            moveToHead(target);
        }
        else
        {
            if(size==cap)
            {
                //需要先删掉最后一个节点
                ListNode1* removed = removeRear();
                hash.erase(removed->key);
                delete removed;
                size--;
            }
            LinkedList newnode=new ListNode1(key,value);
            addToHead(newnode);
            hash.insert({key,newnode});
            size++;
        }
        
    }

    void removeNode(ListNode1* target)
    {
        target->pre->next = target->next;
        target->next->pre = target->pre;
    }

    void addToHead(ListNode1* target)
    {
        target->pre = head;
        target->next = head->next;
        head->next->pre = target;
        head->next = target;
    }

    void moveToHead(ListNode1* target)
    {
        removeNode(target);
        addToHead(target);
    }

    ListNode1* removeRear()
    {
        ListNode1* node = rear->pre;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache l(2);
    l.put(1,1);
    l.put(2,2);

    return 0;

}