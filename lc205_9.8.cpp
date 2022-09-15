//同构字符串
/**
 * @brief 用两个哈希表判断是否是双射
 * 
 */
class Solution {
public:
    //哈希表判断是否是双射
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>hash1,hash2;
        for(int i = 0; i < s.size(); i++) {
            if(hash1.find(s[i]) == hash1.end() && hash2.find(t[i]) == hash2.end()) {
                hash1[s[i]] = t[i];
                hash2[t[i]] = s[i];
            }
            else if(hash1[s[i]] != t[i] || hash2[t[i]] != s[i])
                return false; 
        }

        return true;
    }
};