// https://lightoj.com/problem/best-picnic-ever
//   Using DFS
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(int node, vector<int> ad[], vector<int> &pos, vector<bool> &visited)
{

    visited[node] = true;
    pos[node]++;

    for (auto ch : ad[node])
    {
        if (!visited[ch])
        {
            dfs(ch, ad, pos, visited);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;

    for (int h = 1; h <= t; h++)
    {
        int k, n, m;
        cin >> k >> n >> m;

        vector<int> par;
        while (k--)
        {
            int x;
            cin >> x;
            par.push_back(x);
        }

        vector<int> ad[1010];
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            ad[x].push_back(y);
        }

        vector<int> pos(1010, 0);

        for (auto it : par)
        {
            vector<bool> visited(1010, false);
            dfs(it, ad, pos, visited);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (pos[i] == par.size())
                ans++;
        }

        cout << "Case " << h << ": " << ans << endl;
    }

    return 0;
}
