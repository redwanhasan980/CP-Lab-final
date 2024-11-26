// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=950
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
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    string s, ss;
    vector<int> par(100);
    vector<int> ad[100];
    vector<int> vis(100, 0);
    while (n--)
    {
      cin >> s >> ss;
      ad[s[0] - 'A'].push_back(ss[0] - 'A');
      ad[ss[0] - 'A'].push_back(s[0] - 'A');
    }
    for (z = 0; z < m; z++)
    {
      cin >> s >> ss;
      queue<int> qu;
      qu.push(s[0] - 'A');
      for (i = 0; i < 100; i++)
      {
        par[i] = 0;
        vis[i] = 0;
      }
      while (!qu.empty())
      {
        int flag = 0;
        int node = qu.front();
        qu.pop();
        vis[node] = 1;
        for (auto child : ad[node])
        {
          if (vis[child])
          {
            continue;
          }
          qu.push(child);
          par[child] = node;
          if (child == ss[0] - 'A')
          {
            flag = 1;
            break;
          }
        }
        if (flag == 1)
          break;
      }
      vector<int> ans;

      l = s[0] - 'A';
      r = ss[0] - 'A';
      while (r != l)
      {
        // cout<<(char)(r+'A')<<endl;
        ans.push_back(r);
        r = par[r];
      }
      ans.push_back(s[0] - 'A');
      for (auto it = ans.rbegin(); it != ans.rend(); it++)
      {
        cout << (char)(*it + 'A');
      }
      cout << endl;
    }
    if (t > 0)
      cout << endl;
  }
  return 0;
}