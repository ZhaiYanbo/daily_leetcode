//等差数列划分

/**
 * @brief DP：dp[i][j]表示nums[i..j]是否是等差数列
 *          状态转移方程为：dp[i][j] = dp[i][j-1]&&(nums[j]-nums[j-1] == nums[j-1]-nums[j-2])
 *          O(n^2)
 *          O(n^2)
 * 
 */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();
        if(len < 3)     return 0;
        vector<vector<bool>>dp(len,vector<bool>(len,false));
        int res = 0;

        for(int i = 0; i+2 < len; i++) 
            if(nums[i+2]-nums[i+1] == nums[i+1]-nums[i]) {
                dp[i][i+2] = true;
                res++;
            }

        for(int l = 4;l <= len; l++)
            for(int i = 0; l+i-1 < len; i++) {
                int j = l+i-1;
                dp[i][j] = dp[i][j-1]&&(nums[j]-nums[j-1] == nums[j-1]-nums[j-2]);
                if(dp[i][j])    res++;
            }
        
        return res;

    }
};

/**
 * @brief 一次遍历
 *      O(n)
 *      O(1)
 */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();
        if(len < 3)     return 0;

        int res = 0, d = nums[0] - nums[1], t = 0;
        for(int i = 2; i < len; i++) {
            if(nums[i-1] - nums[i] == d) {
                t++;
            } else {
                d = nums[i-1] - nums[i];
                t = 0;
            }
            res += t;
        }
        
        return res;

    }
};