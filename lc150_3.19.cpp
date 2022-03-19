
//逆波兰表达式
class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int>mystack;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
                mystack.push(stoi(tokens[i]));
            else
            {
                int num1=mystack.top();
                mystack.pop();
                int num2=mystack.top();
                mystack.pop();
                if(tokens[i]=="+")  mystack.push(num2+num1);
                else if(tokens[i]=="-") mystack.push(num2-num1);
                else if(tokens[i]=="*") mystack.push(num2*num1);
                else if(tokens[i]=="/") mystack.push(num2/num1);
            }
            
        }
        return mystack.top();
    }
};
