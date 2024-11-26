// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1594
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

  while (1)
  {
    cin >> r >> c;
    int field[1010][1010] = {0};
    if (r == 0 && c == 0)
      break;
    cin >> n;
    while (n--)
    {
      cin >> x >> k;
      while (k--)
      {
        cin >> y;
        field[x][y] = 1;
      }
    }
    queue<pair<int, int>> qu;
    cin >> x >> y;
    cin >> x1 >> y1;

    int ans = 0;
    int flag = 0;
    qu.push({x, y});
    field[x][y] = 1;
    while (!qu.empty())
    {

      int len = qu.size();

      while (len--)
      {
        auto it = qu.front();

        x = it.first;
        y = it.second;
        qu.pop();
        if (x == x1 && y == y1)
        {
          flag = 1;
          break;
        }
        if (x - 1 >= 0 && field[x - 1][y] == 0)
        {
          qu.push({x - 1, y});
          field[x - 1][y] = 1;
        }
        if (x + 1 < r && field[x + 1][y] == 0)
        {
          qu.push({x + 1, y});
          field[x + 1][y] = 1;
        }
        if (y - 1 >= 0 && field[x][y - 1] == 0)
        {
          qu.push({x, y - 1});
          field[x][y - 1] = 1;
        }
        if (y + 1 < c && field[x][y + 1] == 0)
        {
          qu.push({x, y + 1});
          field[x][y + 1] = 1;
        }
      }
      if (flag == 0)
        ans++;
    }
    cout << ans << endl;
  }
  return 0;
}