//最长递增子序列
//1.DP，时间O（n^2）
class Solution {
public:
    int max_2(int a,int b)
    {
        return a>b?a:b;
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int len=nums.size();
        vector<int>dp(len);
        
        int res=1;
        for(int i=0;i<len;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    dp[i]=max_2(dp[i],dp[j]+1);
            }

            res=max_2(res,dp[i]);
        }
        return res;
    }
};

//2.