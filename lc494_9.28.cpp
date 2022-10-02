//目标和
/**
 * @brief 回溯
 *      O(2^n)
 *      O(n)
 */
class Solution {
public:
    int res;
    int len;
    int target;
    void backTrack(vector<int>& nums,int n,int cur_n) {
        if(n == len) {
            if(cur_n == target)
                res++;
        } else {
            backTrack(nums,n+1,cur_n+nums[n]);
            backTrack(nums,n+1,cur_n-nums[n]);
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        res = 0;
        this->target = target;
        len = nums.size();
        backTrack(nums,0,0);
        return res;
    }
};