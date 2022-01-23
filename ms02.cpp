#include<vector>
#include<string>
#include<set>
#include<iostream>
using namespace std;
int solution(vector<string> &E)
{   
    int N=E.size();
    vector<int>table[10];
    //建立起存储信息的表
    for(int i=0;i<N;i++)
    {
        for(char c:E[i])
            table[c-'0'].emplace_back(i);
    }

    int i,j,res=0;
    for(i=0;i<10;i++)
        for(j=i+1;j<10;j++)
        {
            set<int>avaliable;
            for(auto a:table[i])
                avaliable.insert(a);
            for(auto a:table[j])
                avaliable.insert(a);
            res=max(res,int(avaliable.size()));
        }
    return res;
}

int main()
{
    vector<string>t1={"039","4","14","32","","34","7"} ;
    vector<string>t2={"801234567","180234567","0","189234567","891234567","98","9"} ;
    vector<string>t3={"5421","245","1452","0345","","53","354"} ;

    cout<<solution(t1)<<endl;
    cout<<solution(t2)<<endl;
    cout<<solution(t3)<<endl;
}