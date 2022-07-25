//单词划分
class Solution {
public:
    //DP
    bool wordBreak(string s, vector<string>& wordDict) 
    {

        //创建哈希表
        unordered_set<string>wd(wordDict.begin(),wordDict.end());

        vector<bool>dp(s.size()+1,false);
        dp[0]=true;   //初始条件

        for(int i=1;i<=s.size();i++)
            for(int j=0;j<i;j++)
            {
                if(dp[j]&&wd.find(s.substr(j,i-j))!=wd.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        
        return dp[s.size()];
    }
};