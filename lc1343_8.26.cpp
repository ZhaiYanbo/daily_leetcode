//大小为k且平均值大于等于阈值的子数组的数目

/**
 * @brief 滑动窗，用双指针维护：O（N）
 * 
 */
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        for(int i = 0, j = 0, s = 0; j < arr.size(); j++) {
            s += arr[j];
            if(j-i+1 > k)   s -= arr[i++];
            if(j-i+1 == k&&s >= k * threshold)  res++;
        }

        return res;
    }
};