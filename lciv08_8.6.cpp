//有重复字符串的排列组合
#include<vector>
#include<string>
#include<unordered_set>
#include<iostream>
using namespace std;
class Solution {
private:
    vector<string>res;
    vector<char>track;
    vector<bool>status;
    int len;
    unordered_set<string>set;
public:
    void backtrack(string S)
    {
        //回溯结束
        if(track.size()==len)
        {
            string str = string(track.begin(),track.end());
            //为避免重复，用一个set
            if(set.find(str)==set.end())
            {
                res.emplace_back(str);
                set.insert(str);
            }
                
            return;
            
        }
        for(int i = 0;i < len;i++)
        {
            if(!status[i])
            {
                track.emplace_back(S[i]);
                status[i] = true;
                backtrack(S);
                track.pop_back();
                status[i] = false;
            }
        }
    }
    vector<string> permutation(string S) 
    {
        len = S.size();
        status.resize(len,false);
        backtrack(S);
        return res;
    }   
};

int main()
{
    Solution s;
    string S = "qqe";
    vector<string>res;
    res = s.permutation(S);

    return 0;
}