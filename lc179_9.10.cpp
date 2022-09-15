//最大数
/**
 * @brief 自定义比较函数
 * 
 */
class Solution {
public:
    static bool cmp(string& A,string& B) {
        return A+B > B+A;
    }

    string largestNumber(vector<int>& nums) {
        vector<string>strs;
        for(int num:nums) {
            strs.push_back(to_string(num));
        }

        sort(strs.begin(),strs.end(),cmp);
        string res = "";
        for(string s:strs) {
            res += s;
        }
        //去除前导零
        reverse(res.begin(),res.end());
        int len = res.size();
        while(len-1 && res[len-1] == '0') {
            res.pop_back();
            len--;
        }
        reverse(res.begin(),res.end());
        
        return res==""?0:res;
    }
};