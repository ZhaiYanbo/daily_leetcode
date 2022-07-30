//比较版本号
#include<string>
#include<iostream>
using namespace std;
//C++，双指针法
class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        int len1 = version1.size(),len2 = version2.size();
        int i = 0,j = 0;
        while(i<len1||j<len2)
        {
            long long num1 = 0, num2 = 0;
            for(;i<len1&&version1[i]!='.';i++)
                num1 = num1 *10 + version1[i] -'0';
            for(;j<len2&&version2[j]!='.';j++)
                num2 = num2 *10 + version2[j] -'0';
            
            if(num1>num2)   return 1;
            if(num1<num2)   return -1;
            //跳过点号继续寻找
            i++;
            j++;
        }
        return 0;
    }
};

int main()
{
    string version1 = "1.0";
    string version2 = "1.0.0";
    Solution s;
    cout<<s.compareVersion(version1,version2);

    return 0;
}