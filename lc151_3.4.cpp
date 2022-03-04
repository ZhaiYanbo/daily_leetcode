//反转字符串里的单词
//分三步：去除冗余空格-》反转字符串（这时单词也是反的）-》反转单词
#include<iostream>
#include<algorithm>
using namespace std;
class Solution{
    public:
    void removeExtraSpace(string& s)
    {
        //去除中间的空格
        for(int i=s.length()-1;i>0;i--)
        {
            if(s[i]==s[i-1]&&s[i]==' ')
                s.erase(s.begin()+i);
        }
        //去除字符串首的空格
        if(s.length()>0&&s[0]==' ')
            s.erase(s.begin());
        //去除字符串末的空格
        if(s.length()>0&&s[s.length()-1]==' ')
            s.erase(s.length()-1);
    }
    //因为erase()的复杂度为O(n)，所以上面算法的复杂度为O(n^2),我们再设计一种复杂度为O(n)的算法
    //双指针法
    void removeExtraSpace2(string& s)
    {
        int fastindex=0,slowindex=0;
        //去除字符串首的空格
        while (s.length()>0&&fastindex<s.length()&&s[fastindex]==' ')
        {
            fastindex++;
        }
        //去中间空格
        for(;fastindex<s.length();fastindex++)
        {
            if(fastindex-1>0&&s[fastindex]==s[fastindex-1]&&s[fastindex]==' ')
                continue;
            else
                s[slowindex++]=s[fastindex];
        }
        //去字符串末空格
        if(slowindex-1>0&&s[slowindex-1]==' ')
            s.resize(slowindex-1);
        else    s.resize(slowindex);
    }
    //反转字符串的子串,闭区间[left,right]
    void myReverse(string& s,int left,int right)
    {
        while(left<right)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
    //反转单词
    void reverWords(string& s)
    {
        int start=0,end=0;
        bool entry=false;   //是否在单词区间里的标志
        for(int i=0;i<s.size();i++)
        {   
            //进入单词区间
            if(!entry||s[i]!=' '&&s[i-1]==' ')
            {
                entry=true;
                start=i;
            }
            //字符串未结束，以空格为标志的单词结束
            if(entry&&s[i]==' '&&s[i-1]!=' ')
            {
                entry=false;
                end=i-1;
                myReverse(s,start,end);
            }
            //以字符串结束为标志的单词结束
            if(entry&&i==(s.size()-1)&&s[i]!=' ')
            {
                entry=false;
                end=i;
                myReverse(s,start,end);
            }
        }
    }
    //
    string reverseWords(string s)
    {
        removeExtraSpace(s);
        myReverse(s,0,s.size()-1);
        reverWords(s);
        return s;
    }
};


int main()
{
    string s1=" a  student ";
    Solution solution;
    string s=solution.reverseWords(s1);
    cout<<s;
}