//两个数组的交集
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //set的使用
        //题目中明显提示：1.每个元素唯一    2.不考虑输出结果的顺序
        //综合以上两点，因此使用unordered_set
        unordered_set<int>result_set; 
        unordered_set<int>nums1_set(nums1.begin(),nums1.end());
        for(int num2:nums2)
        {
            if(nums1_set.find(num2)!=nums1_set.end())
                result_set.insert(num2);
        }
        return vector<int>(result_set.begin(),result_set.end());
    }
};
