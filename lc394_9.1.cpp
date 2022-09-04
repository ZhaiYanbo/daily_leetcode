//字符串解码
/**
 * @brief 用栈模拟
 * 
 */
class Solution {
public:
    string mutiString(string& s,int num) {
        string res = "";
        while(num--)    res += s;
        return res;
    }

    /* 用栈模拟 */
    string decodeString(string s) {
        stack<char>stk;
        string res = "";
        string temp_s = "",cnt = "";

        for(char ch:s) {
            if(ch == ']') {
                while(!stk.empty() && stk.top() != '[') {
                    temp_s += stk.top();
                    stk.pop();
                }
                stk.pop();
                reverse(temp_s.begin(),temp_s.end());

                while(!stk.empty() && isdigit(stk.top())) {
                    cnt += stk.top();
                    stk.pop();
                }
                reverse(cnt.begin(),cnt.end());

                temp_s = mutiString(temp_s,stoi(cnt));
                for(char c:temp_s)
                    stk.push(c);
                
                temp_s = "";
                cnt = "";
            }else {
                stk.push(ch);
            }
        }

        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};