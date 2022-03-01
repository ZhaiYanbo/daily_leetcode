//四数之和
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            //if(nums[i]>target) break;     
            //去重逻辑有误，例如nums数组中全是负数，nums[i]=-5>target=-11,但仍有可能满足的情况
            if(i>0&&nums[i]==nums[i-1])     continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(j>i+1&&nums[j]==nums[j-1])   continue;
                int left=j+1,right=nums.size()-1;
                while(left<right)
                {
                    //考虑变态数据，因此用long强制转换
                    if((long)nums[i]+nums[j]+nums[left]+nums[right]<target)   left++;
                    else if((long)nums[i]+nums[j]+nums[left]+nums[right]>target)  right--;
                    else{
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                        while(left<right&&nums[left]==nums[left-1])     left++;
                        while(left<right&&nums[right]==nums[right+1])   right--;
                    }
                }
            }


        }
        return res;
    }
};