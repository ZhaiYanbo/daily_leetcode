//fibonacci数列

//1.递归
class Solution {
public:
    int fib(int n) {
        if(n==0)  return 0;
        if(n==1)  return 1;
        return fib(n-1)+fib(n-2);
    }
};

//2.DP
class Solution {
public:
    int fib(int n) {
        if(n<2)     return n;
        int p=0;
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