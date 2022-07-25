//单词拆分Ⅱ

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->n = s.size();
        this->s = s;

        for (string word : wordDict) {
            wordSet.insert(word);
        }

        return backTrack(0);
    }
private:
    int n;                                      //数组大小
    string s;                                   //字符串
    unordered_map<int, vector<string>> memo;    //用于记忆的哈希表
    unordered_set<string> wordSet;              //单词集合

    vector<string> backTrack(int cur)
    {
        if (cur == n) {
            return {""};  // 达到结尾，返回空字符串
        }

        if (memo.count(cur) > 0) {
            return memo[cur];
        }

        vector<string> result;
        for (int end = cur; end < n; end++) 
        {
            string sub = s.substr(cur, end - cur + 1);  // 获取下个可能的字符，从cur开始，长度为end的子串

            if (wordSet.count(sub)) //存在
            {
                vector<string> rests = backTrack(end + 1);  //当前字符后面的所有路径
                for (string rest : rests) 
                {
                    if (rest == "") 
                    {  // 如果这个路径是空，说明到底了
                        result.push_back(sub);
                    } else 
                    {  // 每个路径头上 加上 当前的字符
                        result.push_back(sub + " " + rest);
                    }
                }
            }
        }

        memo[cur] = result; //记录到memo数组中
        return result;
    }
};