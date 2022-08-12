//132模式

//1.O（n^2）->超时
class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        int len = nums.size();
        if(len<3)   return false;

        int i = 0,j = 0,k;
        int min = nums[0];

        //找出最大值对应的下标j
        for(int j=0;j<len;j++)
        {
            if(nums[j]<min)
            {
                i = j;
                min = nums[j];
            }
            for(int k = j+1;k<len;k++)
            {
                if(nums[k]>min&&nums[k]<nums[j])
                    return true;
            }
        }
            
        return false;
    }
};


//2.单调栈O(N)
class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        int len = nums.size();
        if(len<3)   return false;

        stack<int>candidate;    //单调栈
        int max_k = INT_MIN;
        for(int i = len -1 ;i>=0;i--)
        {
            if(!candidate.empty() && nums[i]<max_k)
            {
                return true;
            }  
            while(!candidate.empty() && candidate.top()<nums[i])
            {
                int temp = candidate.top();
                candidate.pop();
                max_k = temp>max_k?temp:max_k;
            }
            
            candidate.push(nums[i]);
        }

        return false;
    }
};
