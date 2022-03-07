//用栈实现队列

class MyQueue {
private:
    stack<int>stack_in;
    stack<int>stack_out;
public:
    MyQueue() {
       
    }
    
    void push(int x) {
        stack_in.push(x);
    }

    //只有当输出栈为空时，才把输入栈中的数据“倒腾”到输出栈里
    int pop() {
        if(stack_out.empty())
            while(!stack_in.empty())
            {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        
        int temp=stack_out.top();
        stack_out.pop();
        return temp;
    }
    
    int peek() {
        int temp=this->pop();       //代码复用
        stack_out.push(temp);
        return temp;
    }
    
    bool empty() {
        return  stack_in.empty()&&stack_out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */