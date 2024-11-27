

// https://lightoj.com/problem/brush-5
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
        map<int, int> ad[510];
        int ch[510][510];
        for (i = 0; i < 510; i++)
            for (j = 0; j < 510; j++)
                ch[i][j] = 100100;
        while (m--)
        {
            cin >> x >> y >> z;
            if (ch[x][y] > z)
            {
                ad[x][y] = z;
                ch[x][y] = z;
                // cout << "1 ";
            }
            if (ch[y][x] > z)
            {
                ad[y][x] = z;
                ch[y][x] = z;
                // cout << "2";
            }
            //  cout << endl;
        }

        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        vector<int> dis(510, INT_MAX);
        vector<int> vis(510, 0);
        pq.push({0, 1});
        dis[1] = 0;
        while (!pq.empty())
        {
            int node = pq.top()[1];
            pq.pop();
            // cout << node << endl;
            if (vis[node])
                continue;
            vis[node] = 1;

            for (auto it : ad[node])
            {
                int ch = it.first;
                int wt = it.second;
                if (dis[ch] <= dis[node] + wt)
                    continue;
                dis[ch] = dis[node] + wt;
                // cout << ch << endl;
                pq.push({dis[ch], ch});
            }
        }
        cout << "Case " << h << ": ";
        // for (i = 0; i < 10; i++)
        // cout << dis[i] << endl;
        if (dis[n] == INT_MAX)
            cout << "Impossible" << endl;
        else
            cout << dis[n] << endl;
    }

    return 0;
}