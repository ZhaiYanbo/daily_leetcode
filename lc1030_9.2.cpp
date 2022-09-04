//举例顺序排列矩阵单元格

/**
 * @brief 直接bfs
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>>res;
    vector<vector<bool>>matrix;
    int row,col;

    void bfs(int m,int n) {
        queue<pair<int,int>>q;
        pair<int,int>temp(m,n);
        q.push(temp);
        res.push_back({m,n});
        matrix[m][n] = true;
        while(!q.empty()) {
            temp = q.front();
            q.pop();
            m = temp.first;
            n = temp.second;
            
            //上
            if(m-1 >= 0 && !matrix[m-1][n]) {
                q.push({m-1,n});
                res.push_back({m-1,n});
                matrix[m-1][n] = true;
            }
            //下
            if(m+1 < row && !matrix[m+1][n])  {
                q.push({m+1,n});
                res.push_back({m+1,n});
                matrix[m+1][n] = true;
            }
            //左
            if(n-1 >= 0 && !matrix[m][n-1])  {
                q.push({m,n-1});
                res.push_back({m,n-1});
                matrix[m][n-1] = true;
            }
            //右
            if(n+1 < col && !matrix[m][n+1])  {
                q.push({m,n+1});
                res.push_back({m,n+1});
                matrix[m][n+1] = true;
            }
        }
    }
    
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        row = rows;
        col = cols;
        matrix = vector<vector<bool>>(rows,vector<bool>(cols,false));
        bfs(rCenter,cCenter);
        return res;
    }
};