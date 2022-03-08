//有效的括号

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char>mystack;
        for(int i=0;i<s.size();i++)
        {
            if(mystack.size()!=0&&(s[i]==')'
            &&mystack.top()=='('
            ||s[i]=='}'&&mystack.top()=='{'
            ||s[i]==']'&&mystack.top()=='['))  
                mystack.pop();
            else mystack.push(s[i]);
        }
        return mystack.empty();
    }
};