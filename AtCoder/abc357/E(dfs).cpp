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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> vis(n), f(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int j = i;
        vector<int> cyc;
        for (; !vis[j]; j = a[j]) {
            cyc.push_back(j);
            vis[j] = true;
        }
        auto it = find(cyc.begin(), cyc.end(), j);
        if (it == cyc.end()) continue;
        cyc = {it, cyc.end()};
        for (int u : cyc) f[u] = cyc.size();
    }
    auto dfs = [&](auto &&self, int u) {
        if (f[u]) return f[u];
        return f[u] = 1 + self(self, a[u]);
    };
    ll ans = 0;
    for (int i = 0; i < n; i++) ans += dfs(dfs, i);
    cout << ans << "\n";
    return 0;
}