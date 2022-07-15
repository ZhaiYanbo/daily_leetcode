//全排列
class Solution {
public:
    vector<vector<int>>ans; //答案数组
    vector<int>track;   //本次回溯过程中的数组
    vector<bool>status; //表示数组中元素是否被选中
    int n;              
    //回溯函数
    void backtrack(vector<int>nums)
    {
        //回溯结束
        if(track.size()==n) 
        {
            ans.push_back(track);
            return; 
        }
        for(int i=0;i<n;i++)
        {
            if(!status[i])
            {
                track.push_back(nums[i]);
                status[i]=true;
                backtrack(nums);
                track.pop_back();
                status[i]=false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        n=nums.size();
        status.resize(n,false); //初始化状态数组，均未访问
        backtrack(nums);
        return ans;
    }
};