// https://lightoj.com/problem/one-way-roads
// brute force
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
        int ad[110][110] = {500};
        int rad[110][110] = {500};
        int vis[110][110] = {500};

        for (i = 0; i < 110; i++)
            for (j = 0; j < 110; j++)
            {
                ad[i][j] = 500;
                rad[i][j] = 500;
                vis[i][j] = 0;
            }
        for (i = 0; i < n; i++)
        {
            cin >> x >> y >> z;
            // cout << z;
            ad[x][y] = 0;
            ad[y][x] = z;

            rad[x][y] = z;
            rad[y][x] = 0;
        }

        int cur = 1;
        int ans1 = 0;
        int ans2 = 0;

        for (i = 0; i < 101; i++)
        {
            //  cout << ad[cur][i] << endl;
            if (ad[cur][i] == 0)
            {
                ans2 += ad[i][cur];
                vis[cur][i] = 1;
                cur = i;
                break;
            }
        }
        if (cur == 1)
        {
            for (i = 0; i < 101; i++)
            {
                if (rad[cur][i] == 0)
                {
                    ans1 += rad[i][cur];
                    vis[cur][i] = 1;
                    cur = i;
                    break;
                }
            }
        }
        // cout << cur << endl;
        while (cur != 1)
        {
            int flag = 0;
            for (i = 0; i < 101; i++)
            {
                if (vis[i][cur] == 0 && ad[cur][i] == 0)
                {
                    ans2 += ad[i][cur];
                    vis[cur][i] = 1;
                    cur = i;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                for (i = 0; i < 101; i++)
                {
                    if (vis[i][cur] == 0 && rad[cur][i] == 0)
                    {
                        ans1 += rad[i][cur];
                        vis[cur][i] = 1;
                        cur = i;
                        break;
                    }
                }
            }
            // cout << nxt << endl;
        }
        cout << "Case " << h << ": " << min(ans1, ans2) << endl;
    }

    return 0;
}