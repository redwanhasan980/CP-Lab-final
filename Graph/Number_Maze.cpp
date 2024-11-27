
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=870
//  Using Dijkstra
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
    for (h = 1; h <= t; h++)
    {
        cin >> n >> m;
        vector<int> ad[1010];
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
            {
                cin >> x;
                ad[i].push_back(x);
            }

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        pq.push({ad[0][0], 0, 0});
        dis[0][0] = ad[0][0];
        while (!pq.empty())
        {
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            // cout << x << endl;
            if (x == m - 1 && y == n - 1)
                break;

            if (vis[x][y])
                continue;
            vis[x][y] = 1;
            if (x - 1 >= 0 && dis[x - 1][y] > dis[x][y] + ad[x - 1][y])
            {
                dis[x - 1][y] = dis[x][y] + ad[x - 1][y];
                pq.push({dis[x - 1][y], x - 1, y});
            }
            if (x + 1 < n && dis[x + 1][y] > dis[x][y] + ad[x + 1][y])
            {
                dis[x + 1][y] = dis[x][y] + ad[x + 1][y];
                pq.push({dis[x + 1][y], x + 1, y});
            }

            if (y - 1 >= 0 && dis[x][y - 1] > dis[x][y] + ad[x][y - 1])
            {
                dis[x][y - 1] = dis[x][y] + ad[x][y - 1];
                pq.push({dis[x][y - 1], x, y - 1});
            }
            if (y + 1 < m && dis[x][y + 1] > dis[x][y] + ad[x][y + 1])
            {
                dis[x][y + 1] = dis[x][y] + ad[x][y + 1];
                pq.push({dis[x][y + 1], x, y + 1});
            }
        }
        cout << dis[n - 1][m - 1] << endl;
    }

    return 0;
}