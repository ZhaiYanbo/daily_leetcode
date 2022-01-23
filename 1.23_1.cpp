//查找不重复的数
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    //自己思考的方法：前后比较即可
    int singleNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        if(nums.size()==1)
            return nums[0];
        int i;
        for(i=0;i<nums.size();)
        {
            if(nums[i]==nums[i+1])
                i+=2;
            else
                break;
        }
        return nums[i];
    }
    //题解方法，位运算,异或运算
    int singleNumber2(vector<int>& nums)
    {
        int res=0;
        for(int i:nums) res=res^i;
        return res;
    }
};

int main()
{
    vector<int>a={4,1,2,1,2};
    Solution solution;
    cout<<solution.singleNumber(a)<<endl;
    cout<<solution.singleNumber2(a)<<endl;
}