//用队列实现栈

//用双队列
class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int temp;
        while(!q1.empty())
        {
            temp=q1.front();
            q1.pop();
            if(!q1.empty())
                q2.push(temp);
        }
        while(!q2.empty())     
        {
            q1.push(q2.front());
            q2.pop();
        }
        return temp;
    }
    
    int top() {
        int temp;
        for(int i=0;i<q1.size();i++)
        {
            temp=q1.front();
            q1.pop();
            q1.push(temp);
        }
        return temp;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


//用单队列
class MyStack {
public:
    queue<int>q;

    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int temp;
        for(int i=0;i<q.size()-1;i++)
        {
            temp=q.front();
            q.pop();
            q.push(temp);
        }
        temp=q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        int temp;
        for(int i=0;i<q.size();i++)
        {
            temp=q.front();
            q.pop();
            q.push(temp);
        }
        return temp;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */