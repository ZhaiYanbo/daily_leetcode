//螺旋矩阵Ⅱ
//模拟法，循环过程中注意循环不变量
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n,vector<int>(n,0));
        int target=n*n;
        int t=0;
        int b=n-1;
        int l=0;
        int r=n-1;
        int num=1,i;
        while(num<=target)
        {
            for(i=l;i<=r;i++)
                res[t][i]=num++;
            t++;
            for(i=t;i<=b;i++)
                res[i][r]=num++;
            r--;
            for(i=r;i>=l;i--)
                res[b][i]=num++;
            b--;
            for(i=b;i>=t;i--)
                res[i][l]=num++;
            l++;
        }
        return res;
    }
};