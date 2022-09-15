//括号生成
/**
 * @brief 
 * 
 */
class Solution {
    int N;
public:
    void backTrack(vector<string>& res,string cur,int open,int close) {
        if(cur.size() == N*2) {
            res.push_back(cur);
            return ;
        }
            if(open < N)        backTrack(res,cur+"(",open+1,close);
            if(close < open)    backTrack(res,cur+')',open,close+1);
        
    }

    vector<string> generateParenthesis(int n) {
        N = n;
        vector<string>res;
        backTrack(res,"",0,0);
        return res;
    }
};