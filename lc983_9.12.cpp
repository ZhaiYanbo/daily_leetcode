//最低票价
/**
 * @brief dp,从后往前
 * 
 */
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int>travelDay(days.begin(),days.end());
        int dp[366] = {0};
        for(int i = 365; i >= 0; i--) {
            if(travelDay.find(i) != travelDay.end()) {
                dp[i] = min(min(costs[0] + (i+1 > 365?0:dp[i+1]),
                                costs[1] + (i+7 > 365?0:dp[i+7])),costs[2] + (i+30 > 365?0:dp[i+30]));
            } else {
                dp[i] = i+1 > 365?0:dp[i+1];
            }
        }

        return dp[1];
    }
};