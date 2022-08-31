//买股票的最佳时机Ⅱ
/**
 * @brief 脑筋急转弯
 *  只要后一天比前一天价格高，就把这个差累加到结果中
 *  最后返回结果即可
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int ans = 0;
        for(int i = 1;i<prices.size();i++)
        {
            int curProfit = prices[i] - prices[i-1];
            if(curProfit>0) ans+=curProfit;
        }

        return ans;
    }
};