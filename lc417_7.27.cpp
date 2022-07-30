//太平洋、大西洋水流问题
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//1.DFS
class Solution1 {
public:
    const int dire[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    //深度优先搜索
    void dfs(int r,int c,vector<vector<int>>& heights,vector<vector<bool>>& reach)
    {
        if(reach[r][c]) return ;
        reach[r][c]=true;

        for(int i=0;i<4;i++)
        {
            int newr=r+dire[i][0];
            int newc=c+dire[i][1];
            if(newr>=0&&newr<heights.size()&&newc>=0&&newc<heights[0].size()
                &&heights[newr][newc]>=heights[r][c])
                dfs(newr,newc,heights,reach);
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int rn = heights.size();
        int cn = heights[0].size();

        vector<vector<int>>res;

        vector<vector<bool>>pa_reac(rn,vector<bool>(cn,false));
        vector<vector<bool>>at_reac(rn,vector<bool>(cn,false));
  
        for(int i=0;i<rn;i++)
            dfs(i,0,heights,pa_reac);
        for(int i=1;i<cn;i++)
            dfs(0,i,heights,pa_reac);
        for(int i=0;i<rn;i++)
            dfs(i,cn-1,heights,at_reac);
        for(int i=0;i<cn;i++)
            dfs(rn-1,i,heights,at_reac);

        for(int i=0;i<rn;i++)
            for(int j=0;j<cn;j++)
                if(pa_reac[i][j]&&at_reac[i][j])
                {
                    vector<int>temp;
                    temp.emplace_back(i);
                    temp.emplace_back(j);
                    res.emplace_back(temp);
                }

        return res;
        
    }
};


//2.BFS
class Solution2 {
public:
    const int dire[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(int r,int c,vector<vector<int>>& heights,vector<vector<bool>>& reac)
    {
        if(reac[r][c])  return ;
        queue<pair<int,int>>q;
        reac[r][c] = true;
        q.push({r,c});
        while(!q.empty())
        {
            pair<int,int>temp=q.front();
            r = temp.first;
            c = temp.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newr = r +dire[i][0];
                int newc = c +dire[i][1];
                if(newr>=0&&newr<heights.size()&&newc>=0&&newc<heights[0].size()
                    &&heights[newr][newc]>=heights[r][c]&&!reac[newr][newc])
                {
                    reac[newr][newc] = true;
                    q.push({newr,newc});
                }

            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {   
        int nr = heights.size();
        int nc = heights[0].size();

        vector<vector<bool>>pa_reac(nr,vector<bool>(nc,false));
        vector<vector<bool>>at_reac(nr,vector<bool>(nc,false));
        vector<vector<int>>res;

        for(int i=0;i<nr;i++)
            bfs(i,0,heights,pa_reac);
        for(int i=1;i<nc;i++)
            bfs(0,i,heights,pa_reac);
        for(int i=0;i<nr;i++)
            bfs(i,nc-1,heights,at_reac);
        for(int i=0;i<nc-1;i++)
            bfs(nr-1,i,heights,at_reac);

        for(int i=0;i<nr;i++)
            for(int j=0;j<nc;j++)
                if(pa_reac[i][j]&&at_reac[i][j])
                {
                    vector<int>temp;
                    temp.emplace_back(i);
                    temp.emplace_back(j);
                    res.emplace_back(temp);
                }

        return res;
    }
};

int main()
{
    Solution2 s2;
    vector<vector<int>>heights={{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    s2.pacificAtlantic(heights);
    
    return 0;
}