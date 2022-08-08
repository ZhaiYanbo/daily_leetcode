//情侣牵手

//并查集
class UnionFind 
{
private:
    vector<int>parent;
    int count;
public:
    UnionFind(int n) 
    {
        count = n;
        parent.resize(count);
        for(int i=0;i<count;i++)
        {
            parent[i] = i;
        }
    }

    int find(int p)
    {
        while(parent[p]!=p)
        {
            /**路径压缩*/
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    void union_(int p,int q)
    {
        int rootp = find(p),rootq = find(q);
        if(rootp==rootq)    return;
        parent[rootq] = rootp;
        count--;
    }

    int getCount()
    {
        return count;
    }

};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) 
    {
        int cp = row.size()/2;
        UnionFind uf(cp);
        //合并情侣
        for(int i=0;i<row.size();i+=2)
            uf.union_(row[i]/2,row[i+1]/2);
        return cp-uf.getCount();
    }
};