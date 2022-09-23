//通配符匹配


/**
 * @brief dp
 *      O(mn)
 *      O(mn)
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        s = " " + s;
        p = " " + p;
        dp[0][0] = true;
        // for(int i = 1; i <= m; i++)
        //     dp[i][0] = false;
        // for(int j = 1; j <= n; j++)
        //     if(p[j-1] == '*')
        //         dp[0][j] = true;

        for(int j = 1; j <= n; j++) {
            if(p[j] == '*') {
                dp[0][j] = true;
            }
            else {
                break;
            }
        }

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++) {
                if(p[j] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i] == p[j] || p[j] == '?');
                }
            }

        return dp[m][n];
    }
};