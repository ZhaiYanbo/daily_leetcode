//Excel表列序号

class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long  res = 0;
        //int res;
        for(char c:columnTitle) {
            res = res*26 + int(c-'A') +1;
        }

        // return res;
        return int(res);
    }
};