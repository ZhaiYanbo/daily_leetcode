//回文对

/**
 * 1.暴力解法 
 * O(n^2*m),n为字符串数组长度，m为字符串平均长度
 * 超时
 */
class Solution {
public:
    
    bool isPalindrome(string s)
    {
        int l =0, r = s.size()-1;
        while(l<r)
        {
            if(s[l]!=s[r])  return false;
            l++;
            r--;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        vector<vector<int>>res;
        for(int i = 0;i<words.size();i++)
            for(int j = i+1;j<words.size();j++)
            {
                if(isPalindrome(words[i]+words[j]))
                    res.push_back({i,j});
                if(isPalindrome(words[j]+words[i]))
                    res.push_back({j,i});
            }
        return res;
    }
};

/**
 * @brief 
 * 
 */