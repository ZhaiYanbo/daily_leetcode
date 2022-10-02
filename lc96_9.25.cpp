//不同的二叉搜索树

/**
 * @brief dp+数学证明
 *      O(n^2)
 *      O(n)
 */ 
class Solution {
public:
    //dp + 数学证明
    int numTrees(int n) {
        if(n <= 1)  return 1;
        vector<int>g(n+1);
        g[0] = 1;
        g[1] = 1;
        for(int k = 2; k <= n; k++)
            for(int i = 1; i <= k; i++)
                g[k] += g[i-1] * g[k-i];

        return g[n];
    }
    
};