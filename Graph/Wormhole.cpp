// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499
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

        vector<pair<int, int>> ad[1010];
        cin >> n >> m;
        while (m--)
        {
            cin >> x >> y >> z;
            ad[x].push_back({y, z});
        }

        vector<int> dis(1010, INT_MAX);
        dis[x] = 0;
        for (i = 1; i <= n - 1; i++)
        {
            for (int node = 0; node < n; node++)
            {
                if (dis[node] != INT_MAX)
                {
                    for (auto it : ad[node])
                    {
                        int ch = it.first;
                        int wt = it.second;
                        dis[ch] = min(dis[ch], dis[node] + wt);
                    }
                }
            }
        }
        c = 0;
        for (int node = 0; node < n; node++)
        {
            if (dis[node] != INT_MAX)
            {
                for (auto it : ad[node])
                {
                    int ch = it.first;
                    int wt = it.second;
                    if (dis[node] + wt < dis[ch])
                        c++;
                    // dis[ch]=min(dis[ch],dis[node]+wt);
                }
            }
        }
        if (c == 0)
            cout << "not possible" << endl;
        else
            cout << "possible" << endl;
    }

    return 0;
}