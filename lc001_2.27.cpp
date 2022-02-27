//两数之和
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int>hashmap;
        for(int i=0;i<nums.size();i++)
        {
            auto it=hashmap.find(target-nums[i]);
            if(it!=hashmap.end())
                return{it->second,i};
            hashmap.insert(make_pair(nums[i],i));
        }
        return {};   
    }
};