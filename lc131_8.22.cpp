//分割回文串

/* 回溯+dp */
class Solution {
private:
    vector<vector<bool>>dp;  //是否为回文串
    vector<vector<string>>ans;
    vector<string>cur_ans;
public:
    /* 回溯+DP */
    void dfs(const string& s,int i) {
        if(i == s.size()) {
            ans.push_back(cur_ans);
            return ;
        }
        for(int j = i; j < s.size(); j++) {
            if(dp[i][j]) {
                cur_ans.push_back(s.substr(i,j-i+1));
                dfs(s,j+1);
                cur_ans.pop_back();
            }
            
        }
    }
    
    vector<vector<string>> partition(string s) {
        int len = s.size();
        dp.resize(len,vector<bool>(len,false));

        for(int i = 0; i < len; i++) {
            dp[i][i] = true;
            if(i+1 < len) {
                dp[i][i+1] = (s[i] == s[i+1]);
            }
        }
        for(int l = 3; l <= len; l++)
            for(int i = 0; i+l-1 < len; i++) {
                int j = l+i-1;  
                dp[i][j] = dp[i+1][j-1]&&(s[i]==s[j]);
            }
                
        dfs(s,0);
        return ans;
    }
};