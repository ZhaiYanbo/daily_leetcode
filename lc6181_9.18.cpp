//最长的字母序连续子字符串的长度

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int len = s.size();
        vector<int>dp(len);
        int res = 1;
        dp[0] = 1;
        for(int i = 1; i < len ; i++) {
            if(s[i] == s[i-1]+1) {
                dp[i] = dp[i-1] +1;
                res = max(res,dp[i]);
            }
            else {
                dp[i] = 1;
            }
        }
        
        return res;
    }
};