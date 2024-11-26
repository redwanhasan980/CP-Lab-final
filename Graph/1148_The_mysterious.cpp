//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3589
//  Using BFS
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int i, j, i1, i2;
  int x, t, b, k, a, h, m, l, r, z, y1, x2, y2, a1, b1, c1, d1, y, n, x1, d, c, u;
   cin>>t;
  while (t--)
  {   
     vector<int>ad[100100];
     cin>>n;
     while(n--)
     {
       cin>>x>>z;
       while(z--)
       { 
         cin>>y;
         ad[x].push_back(y);
         ad[y].push_back(x);
       }
     }
     cin>>x>>y;
     int ans=0;
     int flag=0;
     queue<int>qu;
     qu.push(x);
     vector<int>vis(100100,0);
     while(!qu.empty()){
       int len=qu.size();
       //cout<<"s"<<endl;
       if (flag==1)
       {
         break;
       }
       ans++;
        while(len--){
           int node=qu.front();
           qu.pop();
           vis[node]=1;
          if(node==y)
          {flag=1;
           break;
          }
          for(auto child : ad[node])
          { 
             if(vis[child])
              continue;
              qu.push(child);
              vis[child]=true;

          }
           
        }
     }
     cout<<x<<" "<<y<<" "<<ans-2<<endl;
     if(t>0)
      cout<<endl;
  }
  return 0;
}