#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //personal solution
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i;
        for(i=0;i<nums.size();i++)
            if(nums[i]==nums[i+nums.size()/2])
                break;
        return nums[i];
    }
    //题解，哈希表记录
    int majorityElement2(vector<int>& nums){
        unordered_map<int,int>hash;
        int res=0,cnt=0;
        for(int num:nums)
        {
            hash[num]++;
            if(hash[num]>cnt)
            {
                cnt=hash[num];
                res=num;
            }
        }
        return res;
        
    }

};