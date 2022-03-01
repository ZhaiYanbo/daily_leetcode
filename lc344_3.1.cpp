//反转字符串
class Solution {
public:
    //题目中要求是原地算法，因此不能开一个栈进行存放
    //使用双指针法
    void reverseString(vector<char>& s) {
        int left=0,right=s.size()-1;
        while(left<right)
        {
            char temp=s[left];
            s[left]=s[right];
            s[right]=temp;
            left++;
            right--;
        }
    }
};