//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=950
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
string s="WELCOMETOSWE";
int counter = 1;
string ss="";
for(int i=0;i<s.size();i++)
{    // cout<<counter<<endl;
    int tem=s[i]+counter;
    //cout<<(char)tem<<endl;
    if(tem>90)
    {
       tem=tem-90;
       tem+=64;

    }
    counter++;
    ss+=(char)tem;
}
cout<<ss<<endl;
return 0;
}