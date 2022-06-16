//探索旋转排序数组
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        //判空
        if(nums.size()==0)  return -1;
        int left=0,right=nums.size()-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)   return mid;
            //mid左右至少有一个有序
            //mid右边有序
            if(nums[mid]<nums[right])
            {
                //正好在右侧有序区间里
                if(nums[mid]<target&&target<=nums[right])   //这里第二个不要忘记写等号
                    left=mid+1;
                //在左侧区间里
                else
                    right=mid-1;
            }
            //mid左边有序
            else
            {
                //正好在左侧有序区间里
                if(nums[left]<=target&&target<nums[mid]) //这里第一个不要忘记写等号
                    right=mid-1;
                //在左侧区间里
                else 
                    left=mid+1;
            }
        }
        return -1;
    }
};