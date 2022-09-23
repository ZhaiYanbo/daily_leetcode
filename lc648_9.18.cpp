//单词替换


/**
 * @brief 哈希集合
 *  O(d+Σ(wi^2)):d是dictionary的字符数，构建哈希集合消耗O(d)时间，
 *      wi是sentence分割后第i个单词的字符数，判断单词的前缀字符串
 *      是否位于哈希集合中消耗O(wi^2)的时间
 *  O(d+s):构建字典集合消耗O(d)，分割sentence消耗O(s)
 */
class Solution {
public:
    //split辅助函数
    vector<string_view>split(string& ss,char c) {
        vector<string_view>res;
        string_view s(ss);
        int pos = 0, start = 0;
        while(pos < s.size()) {
            while(pos < s.size() && s[pos] == c)    pos++;
            start = pos;
            while(pos < s.size() && s[pos] != c)    pos++;
            if(start < s.size())
                res.push_back(s.substr(start,pos-start));
        }
        return res;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        string res;
        unordered_set<string_view>dictionarySet(dictionary.begin(),dictionary.end());
        vector<string_view>words = split(sentence,' ');
        //这里遍历的是引用，在遍历过程中能够修改
        for (auto &word : words) {
            for(int j = 1; j <= word.size(); j++) {
                auto subword = word.substr(0,j);
                //找到了,更新为最短前缀
                if(dictionarySet.find(subword) != dictionarySet.end()) {
                    word = subword;
                    continue;
                }
            }
        }

        for(auto word:words) {
            res += word;
            res += " ";
        }
        res.pop_back(); //去掉最后的空格
        return res;
    }
};

/**
 * @brief Trie
 * 
 */
class Solution {
    struct Trie {
        bool isEnd;
        vector<Trie*> children;
        Trie() : isEnd(false), children(26, NULL){}
    };

    string searhPrefix(Trie* root, const string& word) {
        Trie* cur = root;
        string res;
        for (char c : word) {
            if (cur->children[c - 'a'] == NULL) {
                return "isNotMatch";
            }
            res += c;
            cur = cur->children[c - 'a'];
            if (cur->isEnd == true) return res;
        }
        return "isNotMatch";
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // 构建前缀树Trie
        Trie* root = new Trie();
        for (string& str : dictionary) {
            Trie* cur = root;
            for (char c : str) {
                if (cur->children[c - 'a'] == NULL) {
                    cur->children[c - 'a'] = new Trie();
                }
                cur = cur->children[c - 'a'];
            }
            cur->isEnd = true;
        }
        // 分割字符串
        string word, res;
        stringstream input(sentence);
        while (input >> word) {
            // 查找前缀prefix
            string prefix = searhPrefix(root, word);
            if (prefix != "isNotMatch") {
                res += prefix;
            } else {
                res += word;
            }
            res += " ";
        }
        res.pop_back();
        return res;
    }
};