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
    vector<vector<pair<int, ll> > > g(n + 1);
    int u, v;
    ll w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    
    ll ans = LLONG_MAX;
    vector<bool> vis(n + 1);

    function<void(int, ll)> dfs = [&](int x, ll val) -> void {
        if (x == n) {
            ans = min(ans, val);
            return;
        }

        for (auto &e : g[x]) {
            auto [y, z] = e;
            if (!vis[y]) {
                vis[y] = true;
                dfs(y, val ^ z);
                vis[y] = false;
            }
        }
    };

    vis[1] = true;
    dfs(1, 0);

    cout << ans << "\n";

    return 0;
}