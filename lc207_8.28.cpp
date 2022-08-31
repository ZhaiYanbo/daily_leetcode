//课程表

/**
 * @brief 拓扑排序
 *  图论算法，看排序后得到的数组的长度与课程数目是否相等
 *  若相等，则可以修完课程；若不等，则不能
 */
class Solution {
private:   
    int n;
public:
    vector<int>topSrt(vector<vector<int>>& es) {
        vector<vector<int>>g(n);  //表示图
        vector<int>de(n);         //表示入度
        for(auto e:es) {
            int a = e[0];
            int b = e[1];
            g[a].push_back(b);
            de[b]++;
        }

        queue<int>q;
        for(int i = 0; i < n; i++) {
            if(!de[i])
                q.push(i);
        }

        vector<int>res;
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
            for(auto x:g[t])
                if(--de[x]==0)
                    q.push(x);
        }

        return res;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        auto res = topSrt(prerequisites);
        return res.size() == numCourses;
    }
};