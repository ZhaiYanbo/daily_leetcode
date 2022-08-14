//字符串相乘
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    string addstring(string num1,string num2)
    {
        int len1 = num1.size(), len2 = num2.size();
        if(len2>len1)
        {
            swap(num1,num2);
            swap(len1,len2);
        }
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        num2.append(len1-len2,'0');
        string res = "";
        bool cf = false;  
        for(int i = 0;i<len1;i++)
        {
            int cur = int(num1[i]-'0')+int(num2[i]-'0')+int(cf);
            res.push_back(char(cur%10+'0'));
            cf = cur/10;
        }
        if(cf)  res.push_back('1');
        reverse(res.begin(),res.end());
        return res;
    }

    string multiply(string num1, string num2) 
    {
        if(num1=="0"||num2=="0")    return "0";
        int len1 = num1.size(), len2 = num2.size();
        if(len2<len1)
        {
            string temp = num1;
            num1 = num2;
            num2 = temp;
            int t = len1;
            len1 = len2;
            len2 = t;
        }

        string res = "";
        /**
            zerocnt:要补充0的个数
        */
        for(int zerocnt=0, j = len2-1;j>=0;zerocnt++,j--)
        {
            string cur = "";
            
            int cf = 0;
            for(int i = 0;i<zerocnt;i++)    cur.push_back('0');
            for(int i = len1-1;i>=0;i--)
            {
                int num = int(num1[i]-'0')*int(num2[j]-'0')+cf;
                cur.push_back(char(num%10+'0'));
                cf = num/10;
            }
            if(cf) cur.push_back(char(cf+'0'));
            reverse(cur.begin(),cur.end());
            res = addstring(res,cur);
        }
        return res;
    }
};

int main()
{
    string num1 = "123";
    string num2 = "456";
    Solution s;
    cout<<s.addstring("6150","738")<<endl;
    
    cout<<s.addstring(num1,num2)<<endl;
    cout<<s.multiply(num1,num2)<<endl;
    

    return 0;
}