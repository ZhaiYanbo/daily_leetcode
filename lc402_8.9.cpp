//移掉k位数字

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        vector<char>stk;
        for(int i=0;i<num.size();i++)
        {
            while(!stk.empty()&&k>0&&stk.back()>num[i])
            {
                stk.pop_back();
                k--;
            }
            stk.push_back(num[i]);
        }

        while(k)
        {
            stk.pop_back();
            k--;
        }

        string res="";
        bool leadingZero = true;
        for(int i=0;i<stk.size();i++)
        {
            if(leadingZero&&stk[i]=='0')
               continue;
            leadingZero = false;
            res += stk[i];
        }

        return res==""?"0":res;
    }
};

int main()
{
    Solution s;
    string num1 = "1432219";
    int k1 = 3;
    string num2 = "10200";
    int k2 = 1;
    string num3 = "10";
    int k3 = 2;
    string res = s.removeKdigits(num3,k3);

    return 0;
}