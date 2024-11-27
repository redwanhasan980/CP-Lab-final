// https://lightoj.com/problem/farthest-nodes-in-a-tree
//   Using Dijkstra
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

        cin >> n;
        d = n;
        n--;
        vector<pair<int, int>> ad[100100];
        while (n--)
        {
            cin >> x >> y >> z;
            ad[x].push_back({y, z});
            ad[y].push_back({x, z});
        }
        priority_queue<array<int, 2>, vector<array<int, 2>>, less<array<int, 2>>> pq;
        vector<int> dis(100100, 0);
        vector<int> vis(100100, 0);
        pq.push({0, 0});

        dis[0] = 0;
        int mx = 0;
        int mnode;
        while (!pq.empty())
        {

            int dist = pq.top()[0];
            int node = pq.top()[1];
            // cout << node << endl;
            pq.pop();
            if (dist < dis[node])
                continue;
            if (vis[node])
                continue;

            vis[node] = 1;
            for (auto it : ad[node])
            {
                int wt = it.second;
                int ch = it.first;
                if (dis[ch] >= dis[node] + wt)
                    continue;
                if (vis[ch])
                    continue;
                dis[ch] = dis[node] + wt;
                pq.push({dis[ch], ch});
                if (dis[ch] > mx)
                {
                    mx = dis[ch];
                    mnode = ch;
                }
            }
        }

        priority_queue<array<int, 2>, vector<array<int, 2>>, less<array<int, 2>>> pq1;
        vector<int> dis1(100100, 0);
        vector<int> vis1(100100, 0);
        pq1.push({0, mnode});

        dis1[0] = 0;
        mx = 0;
        mnode;
        while (!pq1.empty())
        {

            int dis1t = pq1.top()[0];
            int node = pq1.top()[1];
            // cout << node << endl;
            pq1.pop();
            if (dis1t < dis1[node])
                continue;
            if (vis1[node])
                continue;

            vis1[node] = 1;
            for (auto it : ad[node])
            {
                int wt = it.second;
                int ch = it.first;
                if (dis1[ch] >= dis1[node] + wt)
                    continue;
                if (vis1[ch])
                    continue;
                dis1[ch] = dis1[node] + wt;
                pq1.push({dis1[ch], ch});
                if (dis1[ch] > mx)
                {
                    mx = dis1[ch];
                    mnode = ch;
                }
            }
        }

        priority_queue<array<int, 2>, vector<array<int, 2>>, less<array<int, 2>>> pq3;
        vector<int> dis3(100100, 0);
        vector<int> vis3(100100, 0);
        pq3.push({0, mnode});

        dis3[0] = 0;
        mx = 0;
        mnode;
        while (!pq3.empty())
        {

            int dis3t = pq3.top()[0];
            int node = pq3.top()[1];
            // cout << node << endl;
            pq3.pop();
            if (dis3t < dis3[node])
                continue;
            if (vis3[node])
                continue;

            vis3[node] = 1;
            for (auto it : ad[node])
            {
                int wt = it.second;
                int ch = it.first;
                if (dis3[ch] >= dis3[node] + wt)
                    continue;
                if (vis3[ch])
                    continue;
                dis3[ch] = dis3[node] + wt;
                pq3.push({dis3[ch], ch});
                // if (dis3[ch] > mx)
                // {
                //     mx = dis3[ch];
                //     mnode = ch;
                // }
            }
        }
        cout << "Case " << h << ":" << endl;
        for (i = 0; i < d; i++)
        {
            cout << max(dis3[i], dis1[i]) << endl;
        }
    }

    return 0;
}
