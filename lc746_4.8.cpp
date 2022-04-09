//最小代价爬楼梯
class Solution {
public:
    //DP solution
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int top=cost.size();
        vector<int>spend(top+1);
        spend[0]=0;
        spend[1]=0;
        for(int i=2;i<=top;i++)
        {
            spend[i]=min((spend[i-1]+cost[i-1]),spend[i-2]+cost[i-2]);
        }

        return spend[top];
    }
};

//空间优化，使用滚动数组
class Solution {
public:
    int min_2(int a,int b)
    {
        return a<b?a:b;
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int top=cost.size();

        int pre1=0;
        int pre2=0;
        int temp;
        for(int i=2;i<=top;i++)
        {
            temp=pre1;
            pre1=min_2(pre1+cost[i-1],pre2+cost[i-2]);
            pre2=temp;
        }
        return pre1;

    }
};