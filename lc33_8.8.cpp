//搜索旋转排序数组

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0, rigth = nums.size()-1;
        while(left<=rigth)
        {
            int mid = (left+rigth)/2;
            if(target == nums[mid])
                return mid;
            /** 左半区间和右半区间至少有一个有序*/
            /*左半区间有序*/
            if(nums[left]<=nums[mid])   /*这里又添加等于是处理left=mid的情况*/
            {   
                /*在左半区间中*/
                if(target>=nums[left]&&target<nums[mid])
                    rigth = mid -1;
                else
                    left = mid +1;
            }
            /*右半区间有序*/
            else
            {
                /*在右半区间中*/
                if(target>nums[mid]&&target<=nums[rigth])
                    left = mid +1;
                else
                    rigth = mid -1;
            }
        }
        return -1;
    }
};