#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    vector<int> dep(n + 1, -1), f(n + 1, -1);
    auto dfs = [&](auto &&self, int u, int fa) -> void {
        dep[u] = dep[fa] + 1;
        f[u] = fa;
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, v, u);
        }
    };
    dfs(dfs, a, 0);
    int ans = 0;
    int steps = (dep[b] + 1) / 2;
    while (steps) {
        b = f[b];
        ans++;
        steps--;
    }
    ans += 2 * (n - 1);

    dfs(dfs, b, 0);
    int mx = *max_element(dep.begin(), dep.end());
    cout << ans - mx << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}