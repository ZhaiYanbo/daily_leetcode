//四数之和
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //存放a+b的哈希表，key与value分别为a+b的值与出现的次数
        unordered_map<int,int>sum_ab;
        for(int a:nums1)
            for(int b:nums2)
                sum_ab[a+b]++;
        //存放结果
        int count=0;
        for(int c:nums3)
            for(int d:nums4)
            {
                auto iter=sum_ab.find(-(c+d));
                if(iter!=sum_ab.end())
                    count+=iter->second;
            }
        return count;
    }
};