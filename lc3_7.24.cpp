//无重复字符的最长字串
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int len = s.size();
        if(len==0)  return 0;
        int left = 0,right = 0,cur = 0,maxlen = 0;
        unordered_map<char,int>hash;
        while(right<len)
        {
            //仅当s[left,right) 中存在s[right]时更新left
            if(hash.find(s[right])!=hash.end()&&hash[s[right]]>=left)
            {
                left = hash[s[right]]+1;
                cur = right - left;                   
            }
           
            hash[s[right]] = right;
            right++;
            cur++;
            maxlen = maxlen>cur?maxlen:cur;          
        }

        return maxlen ;
    }
};