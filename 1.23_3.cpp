#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)   return {};
        sort(nums.begin(),nums.end());
        int i,N=nums.size();
        vector<vector<int> >ans;
        for(i=0;i<N;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;
            int target=-nums[i],left=i+1,right=N-1;
            while(left<right)
            {
                if (nums[left]+nums[right]==target)
                {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right&&nums[left]==nums[left-1]&&nums[right]==nums[right+1])
                    {
                        left++;
                        right--;
                    }

                }
                else if(nums[left]+nums[right]>target)
                    right--;
                else if(nums[left]+nums[right]<target)
                    left++;
            }
        }
        return ans;
    }
};