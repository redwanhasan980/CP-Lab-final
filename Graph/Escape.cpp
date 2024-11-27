// https://lightoj.com/problem/escape
//   Using BFS
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

    for (int h = 1; h <= t; h++)
    {
        int ans = 0;

        cin >> n >> m;
        vector<int> ad[110];
        if (m == 0)
        {
            cout << "Case " << h << ": " << ans << endl;
            continue;
        }
        int tem = 0;
        while (m--)
        {
            cin >> x >> y;
            ad[x].push_back(y);
            ad[y].push_back(x);
            if (x == 1)
                tem++;
            if (y == 1)
                tem++;
        }
        if (tem == 0)
        {
            cout << "Case " << h << ": " << ans << endl;
            continue;
        }
        queue<pair<int, int>> qu;
        qu.push({1, 0});
        int vis[110][2] = {0};

        while (!qu.empty())
        {
            auto it = qu.front();
            qu.pop();
            int node = it.first;
            int state = it.second;
            vis[node][state] = 1;
            for (auto ch : ad[node])
            {
                int tem;
                if (state == 0)
                    tem = 1;
                else
                    tem = 0;
                if (vis[ch][tem] == 0)
                {
                    vis[ch][tem] = 1;
                    qu.push({ch, tem});
                }
            }
        }
        for (i = 1; i <= n; i++)
            if (vis[i][0] == 1)
                ans++;
        cout << "Case " << h << ": " << ans << endl;
    }

    return 0;
}
