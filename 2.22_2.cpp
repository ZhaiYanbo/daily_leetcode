//长度最小的子数组
//1.暴力求解
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        //res初始化为size+1，这是正常情况下不可能的结果
        int res=nums.size()+1;
        int i,j,length;
        for(i=0;i<nums.size();i++)
        {
            int sum=0;
            for(j=i;j<nums.size();j++)
            {
                length=j-i+1;
                sum+=nums[j];
                if(sum>=target)
                    res=res<length?res:length;
            }
            
        }
        //证明未找到这样的数组
        if(res==nums.size()+1)  
            res=0;
        return res;   
    }
};

//2.滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {   
        
        int i=0,j,sum=0,length=nums.size()+1,subLength;
        for(j=0;j<nums.size();j++)     //窗口右边界
        {
            sum+=nums[j];
            while(sum>=target)
            {
                subLength=j-i+1;    //窗口大小
                length=length<subLength?length:subLength;       //不断更新大小
                sum-=nums[i];           
                i++;                //窗口左边界
            }
        }
        if(length==nums.size()+1)   length=0;
        return length;
    }
};