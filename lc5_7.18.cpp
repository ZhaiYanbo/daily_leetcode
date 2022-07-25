//最长回文子串
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//1.暴力：超时
class Solution1 {
public:
    bool isPalindrome(string s)
    {
        int len=s.size();
        if(len==1)  return true;
        int left=0,right=len-1;
        while(left<right)
        {
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    string longestPalindrome(string s) 
    {
        string res="";
        for(int len=1;len<=s.size();len++)
            for(int begin=0;begin+len-1<s.size();begin++)
            {
                if(isPalindrome(s.substr(begin,len)))
                {
                    res=s.substr(begin,len);
                    break;
                }
            }
        return res;
            

    }
};

//2.DP
class Solution2 {
public:
    //DP solution
    string longestPalindrome(string s) 
    {
        int len=s.size();
        if(len==1)  return s;
        vector<vector<int>> dp(len, vector<int>(len,false));//DP二维数组
        int start=0,maxlen=1;
        
        //初始化
        for(int i=0;i<len;i++)
        {
            dp[i][i]=true;
            if(i+1<len&&s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                start=i;
                maxlen=2;
            }
        }
        
        //计算dp表
        for(int l=3;l<=len;l++)     /*l表示长度，从3开始，上边已经处理过1和2的情况了*/
        {
            for(int i=0;i+l-1<len;i++)
            {
                int j=i+l-1;
                dp[i][j]=dp[i+1][j-1]&&(s[i]==s[j]);
                if(dp[i][j])
                {
                    start=i;
                    maxlen=l;
                }
            }
        }
        return s.substr(start,maxlen);
    }
};

int main()
{

    Solution2 s2;
    string s="ccc";
    cout<<s2.longestPalindrome(s);
}