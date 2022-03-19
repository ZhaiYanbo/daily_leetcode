#include<iostream>
using namespace std;
int min_2(int a,int b)
{
    a=a<b?a:b;
    return a<0?0:a;
}
int min_3(int a,int b,int c)
{
    a=a<b?a:b;
    a=a<c?a:c;
    return a<0?0:a;
}
int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int suit1,suit2;
    if(e>f)
    {
        suit1=min_2(a,d);
        suit2=min_3(b,c,d-suit1);
    }
    else
    {        
        suit2=min_3(b,c,d);
        suit1=min_2(a,d-suit2);
    }
    cout<<e*suit1+f*suit2<<endl;
    return 0;
}