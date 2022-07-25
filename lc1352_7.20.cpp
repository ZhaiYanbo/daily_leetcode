//最后k个数的乘积
#include<iostream>
#include<vector>
using namespace std;

class ProductOfNumbers {
private:
    vector<int>acc;     //存放部分积
    int cnt;            //从非0元开始的元素个数
    
public:
    ProductOfNumbers() 
    {
        acc.resize(40010);
        cnt=0;
    }
    
    void add(int num) 
    {
        if(num==0)  cnt=0;
        else
        {
            if(cnt==0)  acc[cnt]=num;
            else    acc[cnt]=acc[cnt-1]*num;
                
            cnt++;
        }
    }
    
    int getProduct(int k) 
    {   
        if(k>cnt)   return 0;
        if(k==cnt)  return acc[cnt-1];
        return acc[cnt-1]/acc[cnt-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

int main()
{
    ProductOfNumbers* obj = new ProductOfNumbers();
    obj->add(3);        // [3]
    obj->add(0);        // [3,0]
    obj->add(2);        // [3,0,2]
    obj->add(5);        // [3,0,2,5]
    obj->add(4);        // [3,0,2,5,4]
    int r1=obj->getProduct(2); // 返回 20 。最后 2 个数字的乘积是 5 * 4 = 20
    int r2=obj->getProduct(3); // 返回 40 。最后 3 个数字的乘积是 2 * 5 * 4 = 40
    int r3=obj->getProduct(4); // 返回  0 。最后 4 个数字的乘积是 0 * 2 * 5 * 4 = 0
    obj->add(8);        // [3,0,2,5,4,8]
    int r4=obj->getProduct(2); // 返回 32 。最后 2 个数字的乘积是 4 * 8 = 32 

    return 0;
}


