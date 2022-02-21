//二分法
//1.闭区间写法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        
        while(left<=right)
        {   
            int mid=(right+left)/2;
            if(nums[mid]>target)
                right=mid-1;
            else if(nums[mid]<target)
                left=mid+1;
            else 
                return mid;
        }
        return -1;
    }
};

//2.左闭右开写法
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left=0,right=nums.size(),mid;
        while(left<right)
        {
            mid=(left+right)/2;
            if(nums[mid]>target)
                right=mid;
            else if(nums[mid]<target)
                left=mid+1;
            else 
                return mid;
        }
        return -1;
    }
};


//经leetcode测试，闭区间写法时间和空间更优