//最长公共前缀
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string res="";    //保存结果
        int minlen=strs[0].size();   //最小字符串长度
        for(int i=1;i<strs.size();i++)
        {
            if(!strs[i].size())    return "";
            minlen=strs[i].size()<minlen?strs[i].size():minlen;
        }
        for(int i=0;i<minlen;i++)
        {
            char c=strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                //该位置字母不相等，直接中断
                if(strs[j][i]!=strs[j-1][i])
                    goto end;
            }
            res+=c;   //该字母在最长公共前缀中
        }
        end:
        return res;
    }
};

int main()
{
    vector<string>strs{"flowers","flow","flight"};
    Solution s1;
    cout<<s1.longestCommonPrefix(strs);
    return 0;
}

