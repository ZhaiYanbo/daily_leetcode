//每日温度
/*判别是否需要使用单调栈，如果需要找到左边或者右边第一个比当前位置的数大或者小，则可以考虑使用单调栈；单调栈的题目如矩形米面积等等*/
//1.单调栈
class Solution {
public:
    //单调栈
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n=temperatures.size();
        vector<int>ans(n);
        stack<int>s;    //单调栈
        s.push(0);
        for(int i=1;i<temperatures.size();i++)
        {
            while(!s.empty()&&temperatures[s.top()]<temperatures[i])
            {
                int temp=s.top();
                ans[temp]=i-temp;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};