//重复的子字符串
class Solution {
public:
    void get_next(int* next,const string s)
    {   
        int j=0;
        next[0]=0;
        for(int i=1;i<s.size();i++)
        {
            while(j>0&&s[i]!=s[j])
                j=next[j-1];
            if(s[i]==s[j])
                j++;
            next[i]=j;
        }
    }

    bool repeatedSubstringPattern(string s) 
    {
        if(s.size()==0) return false;
        //size(s)%(size(s)-next[size-1])=0?
        int next[s.size()];
        get_next(next,s);

        if ( next[s.size()-1]!=0 && ( s.size()%( s.size()-next[s.size()-1] ) ==0) )     return true;
        return false;
    }
};