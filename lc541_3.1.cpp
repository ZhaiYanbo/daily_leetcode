//反转字符串Ⅱ
class Solution {
    void reverseS(string& s,int l,int r){
        while(l<r){
            swap(s[l],s[r]);
            l++;    
            r--;
        }
    }
public:
    string reverseStr(string s, int k) {
        int num=s.length()/(2*k);           //看字符串里最多有几个2k
        for(int i=0;i<num;i++){
            reverseS(s,2*k*i,2*k*i+k-1);    //反转这 2k 字符中的前 k 个字符
        }
        
        if(s.length()%(2*k)<k)                //如果剩余字符少于 k 个，则将剩余字符全部反转。
            reverseS(s,num*2*k,s.length()-1);
        //length和size属性都可以
        //如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样
        //else if(s.length()%(2*k)<2*k&&s.length()%(2*k)>=k) 
        else
            reverseS(s,num*2*k,num*2*k+k-1);
        return s;
    }
};