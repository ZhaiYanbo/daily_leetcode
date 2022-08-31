//重复的DNA序列
/**
 * @brief 哈希
 * 
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        unordered_set<string>record,res;
        for(int i = 0; i <= len-10; i++) {
            string cur = s.substr(i,10);
            if(record.find(cur) != record.end())
                res.insert(cur);
            else
                record.insert(cur);
        }

        return vector<string>(res.begin(),res.end());
    }
};