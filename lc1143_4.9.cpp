//最长公共子序列
class Solution {
public:
    int max_3(int a,int b,int c)
    {
        b=a>b?a:b;
        return b>c?b:c;
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        //加速输入输出，亲测有效
        std::ios::sync_with_stdio(false);
        
        int len1=text1.size();
        int len2=text2.size();
        vector< vector<int> >dp(len1+1,vector<int>(len2+1));
        /*vector初始值为0，所以可以不用初始化*/
        // for(int i=0;i<=len1;i++)
        // {
        //     dp[0][i]=0;
        //     dp[i][0]=0;
        // }
        dp[0][0]=0;
        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++)
                dp[i][j]=max_3(dp[i-1][j-1]+(text1[i-1]==text2[j-1]),dp[i-1][j],dp[i][j-1]);

        return dp[len1][len2];
    }
};