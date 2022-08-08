//连续子数组最大和

class Solution {
public:
    //DP solution
    int maxSubArray(vector<int>& nums) 
    {
        int len = nums.size();
        //dp[i]：以i结尾的连续子数组的最大和
        vector<int>dp(len);
        dp[0] = nums[0];
        int res = nums[0];
        for(int i = 1;i<len;i++ )
        {
            /* 重新开始/继承上一段 */
            dp[i] = nums[i]>(dp[i-1]+nums[i])?nums[i]:(dp[i-1]+nums[i]);
            if(dp[i]>res)
                res = dp[i];
        }
        return res;
    }
};