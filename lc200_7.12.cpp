//岛屿数量（即求连通块数量）

//1.DFS
class Solution {
public:

    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        int nr=grid.size();
        int nc=grid[0].size();

        grid[i][j]='0';
        if(i-1>=0&&grid[i-1][j]=='1')     dfs(grid,i-1,j);    //上
        if(i+1<nr&&grid[i+1][j]=='1')     dfs(grid,i+1,j);    //下
        if(j-1>=0&&grid[i][j-1]=='1')     dfs(grid,i,j-1);    //左
        if(j+1<nc&&grid[i][j+1]=='1')     dfs(grid,i,j+1);    //右
    }

    //DFS求连通块数量   
    int numIslands(vector<vector<char>>& grid) 
    {
        //求出二维网格的行数和列数
        int nr=grid.size();
        if(!nr) return 0;
        int nc=grid[0].size();

        int ans=0;
        for(int i=0;i<nr;i++)
            for(int j=0;j<nc;j++)
                if(grid[i][j]=='1')
                {
                    ans++;
                    dfs(grid,i,j);
                }
        return ans;
    }
};

//2.BFS
class Solution {
public:

    void bfs(vector<vector<char>>& grid,int i,int j)
    {
        int nr=grid.size();
        int nc=grid[0].size();

        queue<pair<int,int>>q;   //广度优先的队列
        grid[i][j]='0';
        pair<int,int>temp(i,j);
        q.push(temp);
        while(!q.empty())
        {
            //取出队首元素
            pair<int,int>nums=q.front();
            q.pop();
            i=nums.first;
            j=nums.second;
            //上
            if(j-1>=0&&grid[i][j-1]=='1')
            {
                grid[i][j-1]='0';
                pair<int,int>temp(i,j-1);
                q.push(temp);   
            }
            //下
            if(j+1<nc&&grid[i][j+1]=='1')
            {
                grid[i][j+1]='0';
                pair<int,int>temp(i,j+1);
                q.push(temp);
            }
            //左
            if(i-1>=0&&grid[i-1][j]=='1')
            {
                grid[i-1][j]='0';
                pair<int,int>temp(i-1,j);
                q.push(temp);
            }
            //右
            if(i+1<nr&&grid[i+1][j]=='1')
            {
                grid[i+1][j]='0';
                pair<int,int>temp(i+1,j);
                q.push(temp);
            }
        }
        
    }

    //广度优先搜索计算连通块数量
    int numIslands(vector<vector<char>>& grid) 
    {
        int nr=grid.size();
        if(!nr) return 0;
        int nc=grid[0].size();
        
        int ans=0;
        for(int i=0;i<nr;i++)
            for(int j=0;j<nc;j++)
                if(grid[i][j]=='1')
                {
                    ans++;
                    bfs(grid,i,j);
                }

        return ans;
    }
};

//3.并查集
class Union_Find
{
private:
    int cnt;  //连通块数量
    vector<int>parent;
public:
    //构造函数
    Union_Find(vector<vector<char>>& grid)
    {
        cnt=0;
        int m=grid.size();
        int n=grid[0].size();
       
        parent.resize(m*n);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    parent[i*n+j]=i*n+j;
                    cnt++;
                }
                
            }
    }
    int find(int x) 
    {
        while (parent[x] != x)			/*不断寻找父节点直到根父节点*/
            x = parent[x];
        return x;
    }

    //连接p与q
    void union_(int p,int q)
    {
        if(!isConnected(p,q))
        {
            parent[find(p)]=find(q);
            cnt--;
        }
            
    }

    //返回连通块数量
    int getcount()
    {
        return cnt;
    }

    //是否联通
    bool isConnected(int p,int q)
    {
        return find(p)==find(q);
    }

};

class Solution 
{
public:
    //并查集
    int numIslands(vector<vector<char>>& grid) 
    {
        int nr=grid.size();
        if(!nr) return 0;
        int nc=grid[0].size();
        Union_Find uf(grid);        //生成并查集对象

        for(int i=0;i<nr;i++)
            for(int j=0;j<nc;j++)
                //因为从左上角开始，所以只合并右与下即可
                if(grid[i][j]=='1')
                {
                    if(i+1<nr&&grid[i+1][j]=='1')    uf.union_(i*nc+j,(i+1)*nc+j);
                    if(j+1<nc&&grid[i][j+1]=='1')    uf.union_(i*nc+j,i*nc+j+1);
                }

        return uf.getcount();
    }
};