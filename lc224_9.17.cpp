//基本计算器
/**
 * @brief 基本计算器：有括号、多位数、只有加减
 *      使用栈保存符号，对数字依次处理
 *      O(n)    O(n)
 */
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int sign = 1;   //表示符号
        stack<int>stk;    //符号栈，因为符号受到括号的叠加，所以考虑用栈
        int i = 0;
        int res = 0;

        stk.push(1);
        while(i < n) {
            char c = s[i];
            //遇到空格直接跳过
            if(c==' ')  i++;
            else if(c=='+') {
                sign = stk.top();
                i++;
            } else if(c=='-') {
                sign = -1*stk.top();
                i++;
            } else if(c=='(') {
                stk.push(sign);
                i++;
            } else if(c==')'){
                stk.pop();
                i++;
            } else {
                long long num = 0;
                while(i < n && isdigit(s[i])) {
                    num = num*10+s[i]-'0';
                    i++;
                }
                res += sign*num;
            }
        }

        return res;
    }
};