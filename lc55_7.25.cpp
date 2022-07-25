//跳跃游戏

//维护最大可到达长度
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int ava=0;
        int len=nums.size();
        int i=0;
        while(i<len-1)
        {
            if(i>ava)   return false;   //达不到，直接返回错误
            ava = ava > i + nums[i] ? ava :  i + nums[i];
            i++;
        }
        return ava>=len-1;
    }
};