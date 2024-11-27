// https://lightoj.com/problem/extended-traffic
//   Using Bellman Ford
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
        cin >> n;
        int wt[210];
        for (i = 1; i <= n; i++)
            cin >> wt[i];

        vector<int> ad[210];
        cin >> m;
        while (m--)
        {
            cin >> x >> y;
            ad[x].push_back(y);
        }
        vector<int> dis(210, INT_MAX);
        dis[1] = 0;
        for (i = 1; i <= n - 1; i++)
        {
            for (int node = 1; node <= n; node++)
            {
                for (auto ch : ad[node])
                {
                    if (dis[node] != INT_MAX)
                    {
                        int w = wt[ch] - wt[node];
                        w = w * w * w;
                        dis[ch] = min(dis[ch], dis[node] + w);
                    }
                }
            }
        }
        cout << "Case " << h << ":" << endl;
        cin >> r;
        while (r--)
        {
            cin >> x;
            if (dis[x] < 3 || dis[x] == INT_MAX)
                cout << "?" << endl;
            else
                cout << dis[x] << endl;
        }
    }

    return 0;
}