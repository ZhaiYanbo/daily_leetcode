//有效的括号字符串

/**
 * @brief 栈（左括号栈、星号栈）
 *  O(N)
 *  o(N)
 */
class Solution {
public:
    bool checkValidString(string s) {
        stack<int>starStack;
        stack<int>leftStack;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c=='(') leftStack.push(i);
            else if(c=='*') starStack.push(i);
            else if(c==')') {
                if(leftStack.empty() && starStack.empty()) 
                    return false;
                if(leftStack.empty())   starStack.pop();
                else leftStack.pop();
            }
        }

        while(!starStack.empty() && !leftStack.empty()) {
            int starIndex = starStack.top();
            starStack.pop();
            int leftIndex = leftStack.top();
            leftStack.pop();
            if(starIndex < leftIndex)
                return false;
        }
        
        return leftStack.empty();
    }
};



/**
 * @brief 贪心（优化空间）
 *  O（n）
 *  O（1）
 */
class Solution {
public:
    bool checkValidString(string s) {
        int maxl = 0, minl = 0;
        for(char c:s) {
            if(c=='(') {
                maxl++;
                minl++;
            }else if(c=='*') {
                maxl++;
                if(minl) minl--;
            }else if(c==')') {
                maxl--;
                if(maxl < 0)    return false;
                if(minl) minl--;
            }

        }

        return minl == 0;

    }
};