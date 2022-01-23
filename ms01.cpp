#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int solution(vector<int> &A)
{
    int res=0;
    unordered_map<int,int>hash;
    for(int i:A)
        hash[i]++;
    //unordered_map<int,int>::iterator it;
    int num,cnt;
    for(auto it=hash.begin();it!=hash.end();it++)
    {
        num=it->first;
        cnt=it->second;
        if(cnt>num)
            res+=cnt-num;
        else if(cnt<float(num)/2)
            res+=cnt;
        else 
            res+=num-cnt;
    }
    return res;
}

int main()
{
    vector<int>a1={1,1,3,4,4,4};
    vector<int>a2={1,2,2,2,5,5,5,8};
    vector<int>a3={1,1,1,1,3,3,4,4,4,4,4};
    vector<int>a4={10,10,10};
    cout<<solution(a1)<<endl;
    cout<<solution(a2)<<endl;
    cout<<solution(a3)<<endl;
    cout<<solution(a4)<<endl;
}
