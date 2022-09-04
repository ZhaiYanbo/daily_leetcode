//零钱兑换

/**
 * @brief dp
 * 
 */

class Solution {
public:
    //DP
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)   return 0;
        int len = coins.size();
        vector<int>dp(amount+1,amount+1);  
        /* 先取一个不合理的最大值amount+1,若最后答案为amount+1，则返回-1 */

        dp[0] = 0;
        for(int s = 1; s <= amount; s++) {
            for(int c:coins) {
                if(s-c >= 0) {
                    dp[s] = min(dp[s],dp[s-c]+1);
                }
            }
        }

        return dp[amount]==amount+1?-1:dp[amount];
    }
};