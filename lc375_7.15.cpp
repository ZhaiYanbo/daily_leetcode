//猜数字
class Solution {
public: 
    //DP solution
    int getMoneyAmount(int n) 
    {
        if(n==1)    return 0;
        int dp[n+1][n+1];   //dp数组，0号元素不用，所以开n+1
        
        //赋初值
        for(int i=0;i<n+1;i++)
            for(int j=0;j<n+1;j++)  
                dp[i][j]=INT_MAX;       //C++中INT_MAX
        
        //对角线赋0:dp[i][i]=0
        for(int i=1;i<=n;i++)
            dp[i][i]=0;

        //根据状态转移方程计算dp数组
        /*从第2列开始，每一列从下往上打表*/
        for(int j=2;j<=n;j++)
            for(int i=j-1;i>0;i--)
                /*中间情况：min{max(dp[i][k-1],dp[k+1][j])+k},k>=i+1&&k<=j-1 
                  两端情况：i+dp[i+1][j],j+dp[i][j-1],
                  dp取上述值中最小的即可*/
                  {
                    for(int k=i+1;k<=j-1;k++)
                        dp[i][j]=min(dp[i][j],max(dp[i][k-1],dp[k+1][j])+k);
                    dp[i][j]=min(dp[i][j],i+dp[i+1][j]);
                    dp[i][j]=min(dp[i][j],j+dp[i][j-1]);
                  }
        return dp[1][n];
    }
};