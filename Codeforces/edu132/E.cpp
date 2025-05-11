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
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int> > g(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> w(n);
    vector<set<int>> s(n);
    int ans = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        s[u] = {w[u]};
        bool ok = true;
        for (int v : g[u]) {
            if (v == p) continue;
            w[v] = w[u] ^ a[v];
            dfs(v, u);

            if (!ok) continue;
            if (s[v].size() > s[u].size()) swap(s[u], s[v]);
            for (int x : s[v]) {
                if (s[u].count(x ^ a[u])) {
                    ok = false;
                    ans++;
                    s[u].clear();
                    break;
                }
            }

            if (ok) {
                for (int x : s[v]) s[u].insert(x);
            }

            s[v].clear();
        }
    };
    dfs(0, -1);
    cout << ans << "\n";
    return 0;
}