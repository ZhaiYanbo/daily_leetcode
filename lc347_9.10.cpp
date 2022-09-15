//前k个高频元素

/**
 * @brief 维护小根堆
 * 时间：O(Nlogk),N为数组长度，k为堆的大小
 * 空间：O(N)
 */
class Solution {
public:
    static bool cmp(const pair<int,int>&a,const pair<int,int>&b) {
        //小根堆，使用大于号
        return a.second > b.second;
    }

    /* 使用小根堆 */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        unordered_map<int,int>occurrences;
        //建立次数表
        for(int num:nums) {
            occurrences[num]++;
        }

        //小根堆
        //decltype()要传入的是一个对象的地址，因此需要对cmp加取值符，&cmp为对象的地址
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)>h(cmp);
        for(auto it:occurrences) {
            if(h.size() < k) {
                h.push({it.first,it.second});
            }
            else {
                if(h.top().second > it.second) continue;
                h.pop();
                h.push({it.first,it.second});
            }
        }

        //得到结果数组
        while(!h.empty()) {
            res.push_back(h.top().first);
            h.pop();
        }

        return res;
    }
};

/**
 * @brief 
 * 
 */