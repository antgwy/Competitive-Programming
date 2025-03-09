#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<pii> > g(n + 1);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    vector<int> t(n + 1), ans(n + 1);
    vector<bool> vis(n + 1);

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vector<int> cc;

        queue<int> q;
        t[i] = 0;
        vis[i] = true;
        q.push(i);

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            cc.push_back(x);
            
            for (auto &e : g[x]) {
                auto [y, z] = e;
                if (!vis[y]) {
                    vis[y] = true;
                    t[y] = t[x] ^ z;
                    q.push(y);
                }
                else if (t[y] != (t[x] ^ z)) {
                    cout << "-1\n";
                    exit(0);
                }
            }
        }

        int val = 0;
        for (int bit = 0; bit < 32; bit++) {
            int c0 = 0, c1 = 1;
            for (auto ver : cc) {
                if (t[ver] >> bit & 1) c1++;
                else c0++;
            }
            if (c1 > c0) val |= (1 << bit);
        }

        for (auto ver : cc) {
            ans[ver] = t[ver] ^ val;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }

    return 0;
}