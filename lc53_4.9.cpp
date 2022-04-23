//最大子数组的和
//1.DP
class Solution {
public:
    int max_2(int a,int b)
    {
        return a>b?a:b;
    }
    //DP solution
    int maxSubArray(vector<int>& nums) 
    {
        int len=nums.size();
        vector<int>dp(len);
        dp[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<len;i++)
        {
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

//2.空间优化，直接在原数组上操作
class Solution {
public:
    int max_2(int a,int b)
    {
        return a>b?a:b;
    }
    //DP solution
    int maxSubArray(vector<int>& nums) 
    {
        int len=nums.size();
    
        int ans=nums[0];
        for(int i=1;i<len;i++)
        {
            nums[i]=max_2(nums[i-1]+nums[i],nums[i]);
            ans=max_2(ans,nums[i]);
        }
        return ans;
    }
};
