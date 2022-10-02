//连续数组
/**
 * @brief 哈希+前缀和
 *      o(n)
 *      o(n)
 */
class Solution {
public:
    // hash + 前缀和
    int findMaxLength(vector<int>& nums) {
        int ans = 0, sum = 0;
        unordered_map<int,int>mp;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i]?1:-1;
            auto p = mp.find(sum);
            if(p != mp.end())     ans = max(ans,i - p->second);
            else    mp[sum] = i;
        }

        return ans;
    }
};