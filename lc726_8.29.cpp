//原子的数量

/**
 * @brief 模拟，从后向前线性遍历一遍
 * 
 */

class Solution {
public:
    string countOfAtoms(string formula) {
        string d = "",s = "";   //d与s分别表示数字与字符串
        int cnt = 1;        //表示倍数
        int len = formula.size();
        stack<int>stk;      //存储一层一层括号后面的倍数
        map<string,int>atoms;     //记录每一种原子的个数
        //从后向前遍历
        for(int i = len -1; i >= 0; i--) {
            if(isdigit(formula[i])) {
                d = formula[i] + d ;
            }else if(formula[i] == ')') {
                int v = (d == "")?1:stoi(d);
                d = "";
                cnt *= v;
                stk.push(v);
            }else if(formula[i] == '(') {
                cnt /= stk.top();
                stk.pop();
            }else{
                s += formula[i];
                if(formula[i] >= 'A' && formula[i] <= 'Z') {
                    reverse(s.begin(),s.end());
                    atoms[s] += (d==""?1:stoi(d))*cnt;
                    d = "";
                    s = "";
                }
            }
        }

        for(auto it:atoms) {
            s += it.first;      //记录值
            if(it.second>1)     s += to_string(it.second);
        }

        return s;
    }
};