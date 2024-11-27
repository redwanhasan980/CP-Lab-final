// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=319
//  Using Floyed Warshell
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
    cout << "SHIPPING ROUTES OUTPUT" << endl
         << endl;
    for (z = 1; z <= t; z++)
    {
        cin >> n >> m >> h;

        l = n;
        map<string, int> mp;
        c = 0;
        while (n--)
        {
            string s;
            cin >> s;
            mp[s] = c++;
        }
        int dis[50][50];
        for (i = 0; i < 50; i++)
        {
            for (j = 0; j < 50; j++)
            {
                dis[i][j] = 500;
            }
        }
        for (j = 0; j < 50; j++)
        {
            dis[j][j] = 0;
        }
        cout << "DATA SET  " << z << endl
             << endl;
        while (m--)
        {
            string s, ss;
            cin >> s >> ss;
            dis[mp[s]][mp[ss]] = 1;
            dis[mp[ss]][mp[s]] = 1;
        }
        for (k = 0; k < l; k++)
        {
            for (i = 0; i < l; i++)
            {
                for (j = 0; j < l; j++)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        while (h--)
        {
            cin >> a;
            string s, ss;
            cin >> s >> ss;
            if (dis[mp[s]][mp[ss]] == 500)
            {
                cout << "NO SHIPMENT POSSIBLE" << endl;
            }
            else
            {
                // cout << dis[mp[s]][mp[ss]] << endl;
                cout << "$" << a * dis[mp[s]][mp[ss]] * 100 << endl;
            }
        }
        cout << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}