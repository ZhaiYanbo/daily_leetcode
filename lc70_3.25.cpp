//爬楼梯
class Solution {
public:
    int climbStairs(int n) 
    {
        if(n==1||n==0)  return 1;
        //这里的n==2并没有对应任何的实际场景，只是为了方便后面的计算。
        int p=1;
        int q=1;
        int r=p+q;
        while(n-2)
        {
            p=q;
            q=r;
            r=p+q;
            n--;
        }
        return r;
    }
};