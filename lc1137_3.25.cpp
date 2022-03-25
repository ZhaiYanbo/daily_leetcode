/*
泰波那契序列 Tn 定义如下： 

T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2

给你整数 n，请返回第 n 个泰波那契数 Tn 的值。

*/
class Solution {
public:
    int tribonacci(int n) 
    {
        if(n==0)    return 0;
        if(n==1||n==2)    return 1;
        int p=0;
        int q=1;
        int r=1;
        int s=p+q+r;
        while(n-3)
        {
            p=q;
            q=r;
            r=s;
            s=p+q+r;
            n--;
        }
        return s;
    }
};