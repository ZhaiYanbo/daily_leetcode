//俄罗斯套娃信封问题
//1.Dp
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        sort(envelopes.begin(),envelopes.end());
        int len=envelopes.size();
        vector<int>dp(len);
        int res = 1;
        for(int i=0;i<len;i++)
        {
            dp[i]=1;
            for( int j = 0;j<i;j++)
            {
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1])
                    dp[i] = dp[i]>(dp[j]+1)?dp[i]:(dp[j]+1);
            }
            res = res>dp[i]?res:dp[i];
        }

        return res;
    }
};


//2.二分
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });

        vector<int> f = {envelopes[0][1]};
        for (int i = 1; i < n; ++i) {
            if (int num = envelopes[i][1]; num > f.back()) {
                f.push_back(num);
            }
            else {
                auto it = lower_bound(f.begin(), f.end(), num);
                *it = num;
            }
        }
        return f.size();
    }
};
