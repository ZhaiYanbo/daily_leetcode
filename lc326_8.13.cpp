//3的幂

#include<iostream>
#include<math.h>
using namespace std;
//1.循环
class Solution1 {
public:
    bool isPowerOfThree(int n) 
    {
        while(n&&n%3==0)
        {
            n/=3;
        }
        return n==1;
    }
};

//2.利用边界
class Solution2 {
public:
/**
 * @brief 经检验，3的19次方为上限，所以只用看n是否为3的19次方的因数即可
 * 
 * @param n 
 * @return true 
 * @return false 
 */
    bool isPowerOfThree(int n)
    {
       return (n>0)&&(1162261467%n==0);
    }
};

int main()
{
    //cout<<(pow(3,19)>pow(2,31)-1)<<endl;
    cout<<pow(3,19.0)<<endl;
    return 0;
}