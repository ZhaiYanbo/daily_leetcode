//接雨水

/**
 * @brief DP
 * 
 */
class Solution {
public:x`
    //DP
    int trap(vector<int>& height) {
        int len = height.size();
        int res = 0;
        vector<int>rigth_max(len),left_max(len);
        rigth_max[len-1] = height[len-1];
        left_max[0] = height[0];

        for(int i = 1; i < len; i++)
            left_max[i] = max(left_max[i-1],height[i]);

        for(int i = len - 2; i >= 0; i--)
            rigth_max[i] = max(rigth_max[i+1],height[i]);

        for(int i = 0 ;i < len; i++)
            res += min(left_max[i],rigth_max[i]) - height[i];

        return res;
    }
};