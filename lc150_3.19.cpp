//逆波兰表达式
class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<string>mystack;
    
        for(int i=0;i<tokens.size();i++)
        {
            int num1,num2;
            if(tokens[i]!="+"
            &&tokens[i]!="-"
            &&tokens[i]!="*"
            &&tokens[i]!="/")
            {
                mystack.push(tokens[i]);
            }
            else
            {
                num1=stoi(mystack.top());
                mystack.pop();
                num2=stoi(mystack.top());
                mystack.pop();
                if(tokens[i]=="+")
                    mystack.push(to_string(num2+num1));
                else if(tokens[i]=="-")
                    mystack.push(to_string(num2-num1));
                else if(tokens[i]=="*")
                    mystack.push(to_string(num2*num1));
                else if(tokens[i]=="/")
                    mystack.push(to_string(num2/num1));
                
            }
        }
        return stoi(mystack.top());
            
    }
};