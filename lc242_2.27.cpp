//有效的字母异位词
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        //将a-z映射到长度为26的数组中进行保存，其中每个单元存储对应字母出现的次数
        vector<int>alphabet(26);
        for(char c:s)   alphabet[c-'a']++;
        for(char c:t)   alphabet[c-'a']--;
        for(int i:alphabet)
            if(i)   return false;
        return true;
    }
};