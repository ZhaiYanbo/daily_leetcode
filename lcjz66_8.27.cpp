//构建乘积数组

/**
 * @brief 暴力解法：O（N^2），O（1）
 *  超时
 */
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int>res;
        for(int i = 0; i < a.size(); i++) {
            int accu = 1;
            for(int j = 0; j < a.size(); j++) {
                if(j==i)    continue;
                accu *= a[j];
            }
            res.push_back(accu);
        }

        return res;
    }
};

/**
 * @brief 借助左右累乘数组
 *  O（N）、O（N）
 */
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        if(len==0)  return {};
        vector<int>L(len),R(len),res(len);   //分别表示从左边到该位置的累乘和从右边到该位置的累乘

        L[0] = a[0];
        for(int i = 1; i < a.size(); i++) {
            L[i] = L[i-1] * a[i];
        }

        R[len-1] = a[len-1];
        for(int j = len-2; j>=0; j--) {
            R[j] = R[j+1] * a[j];
        }

        res[0] = R[1];
        res[len-1] = L[len-2];
        for(int i = 1; i < len-1; i++){
            res[i] = L[i-1] * R[i+1];
        }
        
        return res;
    }
};

/**
 * @brief 在2的基础上节省空间
 *  O(N),O(1)
 */
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        if(len==0)  return {};
        vector<int>res(len);

        //res数组先存从左边到该位置的累乘
        res[0] = a[0];
        for(int i = 1; i < a.size(); i++) {
            res[i] = res[i-1] * a[i];
        }

        int R = 1;   //R表示从右边到该位置的累乘，初始值为1
        for(int j = len-1; j>0; j--) {
            res[j] = res[j-1] * R;
            R *= a[j]; 
        }
        res[0] = R;
        
        return res;
    }
};