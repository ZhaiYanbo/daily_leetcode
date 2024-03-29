//第一个错误版本

//二分
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left <= right) {
            if(left == right)   return left;
            unsigned int mid = (unsigned int)(left)+right>>1;
            if(isBadVersion(mid))   right = mid;
            else                    left  = mid+1;
        }

        return -1;
    }
};