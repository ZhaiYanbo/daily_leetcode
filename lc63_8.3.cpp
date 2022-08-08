//不同路径Ⅱ

//DPSolution
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if(obstacleGrid[0][0])  return 0;
        int nr = obstacleGrid.size(),nc = obstacleGrid[0].size();
        if(nr==1&&nc==1&&obstacleGrid[0][0]==0) return 1;
        vector<vector<int>>dp(nr,vector<int>(nc));
        /**初始化dp表 */
        for(int i = 1;i<nr;i++)
        {
            if(obstacleGrid[i][0])  break;
            dp[i][0] = 1;
        }
            
        for(int j = 1;j<nc;j++)
        {
            if(obstacleGrid[0][j])  break;
            dp[0][j] = 1;
        }
        //计算dp表
        for(int i = 1;i<nr;i++)
            for(int j = 1;j<nc;j++)
                dp[i][j]=obstacleGrid[i][j]?0:dp[i-1][j]+dp[i][j-1];
        return dp[nr-1][nc-1];
    }
};