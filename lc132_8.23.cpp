//分割回文串Ⅱ

/**
 * @brief 1.回溯+dp
 *      O(N*2^N)
 */
class Solution {
private:
    int mincnt;
    vector<vector<bool>>dp;
    vector<vector<string>>res;
    vector<string>cur_res;
public:
    void dfs(string s,int i) {
        if(i==s.size()) {
            mincnt = cur_res.size()-1 < mincnt ? cur_res.size()-1 : mincnt;
            return ;
        }
        for(int j = i;j<s.size();j++) {
            if(dp[i][j]) {
                cur_res.push_back(s.substr(i,j-i+1));
                dfs(s,j+1);
                cur_res.pop_back();
            }
        }
    }

    int minCut(string s) {
        int len = s.size();
        mincnt = len;
        dp.resize(len,vector<bool>(len,false));

        for(int i =0; i < len; i++) {
            dp[i][i] = true;
            if(i+1 < len) {
                dp[i][i+1] = s[i]==s[i+1];
            }
        }

        for(int l =3;l<=len;l++)
            for(int i=0;i+l-1<len;i++) {
                int j = l+i-1;
                dp[i][j] = dp[i+1][j-1]&&(s[i] == s[j]);
            }

        dfs(s,0);
        return mincnt;
    }

};

/**
 * @brief 2.动态规划
 *  O(N^2)
 */

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<vector<bool>>dp(len,vector<bool>(len,true)); //表示是否是回文串
        vector<int>f(len,INT_MAX);  //存储结果

        for(int i = len-1; i >= 0; i--) {
            for(int j = i+1; j < len; j++) {
                dp[i][j] = dp[i+1][j-1]&&(s[i]==s[j]);
            }
        }

        f[0] = 0;
        for(int i = 1; i < len; i++) {
            if(dp[0][i])
                f[i] = 0;
            else {
                for(int j = 0; j < i; j++) {
                    if(dp[j+1][i])
                        f[i] = f[j] + 1 < f[i] ? f[j] + 1 : f[i];
                }
            }
            
        }

        return f[len-1];
    }
};