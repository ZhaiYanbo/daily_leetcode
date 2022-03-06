//实现strStr()
class Solution {
public:
    //KMP

    //生成next数组
    void get_next(int* next,const string s)
    {
        //i，j分别表示后缀末尾为与前缀末尾
        int j=0;    
        next[0]=0;
        for(int i=1;i<s.size();i++)
        {
            //如果新增的字符不匹配，则j回溯
            while(j>0&&s[i]!=s[j])
                j=next[j-1];
            if(s[i]==s[j])
                j++;
            //此时j的值即为下表为i的next数组的值
            next[i]=j;
        }
    }

    int strStr(string haystack, string needle) 
    {
        int m=haystack.size(),n=needle.size();
        //特判
        if(!n)  return 0;
        //获得next数组
        int next[n];
        get_next(next,needle);

        int j=0;
        for(int i=0;i<m;i++)
        {
            while(j>0&&haystack[i]!=needle[j])
            {
                j=next[j-1];
            }
            if(haystack[i]==needle[j])
            {
                j++;
            }
            //匹配成功
            if(j==n)
                return i-j+1;
        }
        //匹配失败
        return -1;
    }
};