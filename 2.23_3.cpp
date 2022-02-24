//设计链表
#include<stdio.h>
#include<iostream>
using namespace std;
//  Mine--------------------------------------------
class MyLinkedList {
public:
    struct linkedNode{
        int val;
        linkedNode* next;
        linkedNode():val(0),next(NULL){}
        linkedNode(int val):val(val),next(NULL){}
    };

    MyLinkedList() {
        _dummyhead=new linkedNode();     //虚拟头节点
        _size=0;
    }
    
    int get(int index) {
        if(index<0||index>=_size)
            return -1;
        linkedNode* cur=_dummyhead->next;
        while(index--)
        {
            cur=cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {

        linkedNode* newNode=new linkedNode(val);
        newNode->next=_dummyhead->next;
        _dummyhead->next=newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        
        linkedNode* newNode=new linkedNode(val);
        //listNode* cur=_dummyhead->next;
        linkedNode* cur=_dummyhead;
        while(cur->next!=NULL)
            cur=cur->next;
        cur->next=newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        
        if(index>_size)
            return;
        else if(index<=0)
            addAtHead(val);
        else
        {
            linkedNode* newNode=new linkedNode(val);
            linkedNode* cur=_dummyhead;
            while(index--)      //使cur指向要添加的节点的前一个节点
            {
                cur=cur->next;
            }
            newNode->next=cur->next;
            cur->next=newNode;
        }
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>=_size)   return;
        linkedNode* cur=_dummyhead;
        while(index--)  cur=cur->next;  //使cur指向要添加的节点的前一个节点
        linkedNode* temp=cur->next;
        cur->next=cur->next->next;
        delete temp;
        _size--;
    }
   // 打印链表
    void printLinkedList() {
        linkedNode* cur = _dummyhead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    private:
        int _size;
        linkedNode*  _dummyhead;
};

/*  Carl--------------------------------
class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };

    // 初始化链表
    MyLinkedList() {
        _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }

    // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while(index--){ // 如果--index 就会陷入死循环
            cur = cur->next;
        }
        return cur->val;
    }

    // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // 在链表最后面添加一个节点
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    void addAtIndex(int index, int val) {
        if (index > _size) {
            return;
        }
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur ->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }

    // 打印链表
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int _size;
    LinkedNode* _dummyHead;

};
*/

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main()
{

    MyLinkedList* linkedList=new MyLinkedList() ;
    linkedList->addAtHead(1);
    linkedList->printLinkedList();
    
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1,2);   //链表变为1-> 2-> 3
    linkedList->printLinkedList();
    cout<<linkedList->get(1)<<endl;            //返回2
    linkedList->deleteAtIndex(1);  //现在链表是1-> 3
 
    linkedList->printLinkedList();
    cout<<linkedList->get(1);            //返回3
    

}