//搜索旋转排序数组Ⅱ

/**
 * @brief 1.二分法
 * 添加nums[mid] == nums[left] == nums[right]
 * 时的区间收缩情况
 * o(n)
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int left = 0, right = nums.size()-1;

        while(left <= right) {
            int mid = (left + right)>>1;
            if(nums[mid] == target)  return true;
            /* 左半区间与右半区间至少有一个有序 */
            /* 左半区间有序 */
            if(nums[mid] == nums[left] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            else if(nums[mid] >= nums[left]) {
                //刚好在有序的半个区间内
                if(target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                //在无序的半个区间内
                else
                    left = mid + 1;
            } 
            /* 右半区间有序 */
            else{
                //刚好在有序的半个区间内
                if(target > nums[mid] && target <= nums[right])
                    left = mid + 1;  
                //在无序的半个区间内
                else
                    right = mid - 1;
            }
            
        }

        return false;

    }
};

/**
 * @brief 2.暴力搜索
 * O(n)
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int num:nums) {
            if(num == target)  return true;
        }
        return false;
    }
};