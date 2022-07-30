//大数加法（两个字符串相加，结果仍以字符串的形式返回）

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) 
    {   
        int len1 = num1.size(),len2 = num2.size();

        if(len2 > len1)
        {
            string temp = num1;
            num1 = num2;
            num2 = temp;
            swap(len1,len2);
        }

        int i = len1 -1, j = len2 -1;
        int cf = 0;
        string res = "";
        while(j >= 0)
        {
            int s = int(num1[i])+int(num2[j])-2*int('0')+cf;
            cf = s/10;
            s %= 10;
            res.push_back(s+'0');
            i--;
            j--;
        }
        while( i>=0 )
        {
            int s = int(num1[i])-int('0')+cf;
            cf = s/10;
            s %= 10;
            res.push_back(s+'0');
            i--;
        }
        if(cf)  res.push_back('1');

        reverse(res.begin(),res.end());
        return res;
    }
};

int main()
{
    Solution s;
    string s1="456";
    string s2="77";
    cout<<s.addStrings(s1,s2)<<endl;

    return 0;
}