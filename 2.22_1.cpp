//删除数组中指定元素
//1.暴力解法
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int i,j,size=nums.size();
        for(i=0;i<size;i++)
            if(nums[i]==val)
            {   
                size--;
                for(j=i+1;j<nums.size();j++)
                    nums[j-1]=nums[j];
                i--;
            }
        return size;      
    }
};

//2.双指针（快慢指针）
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {   
        int slowIndex=0;
        for(int fastIndex=0;fastIndex<nums.size();fastIndex++)
            if(nums[fastIndex]!=val)
                nums[slowIndex++]=nums[fastIndex];
            //else  等于就跳过，下一轮循环
        return slowIndex;
    }
};
