#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > e(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    vector<int> id(n, -1), dfn(n, -1), low(n, -1), w(n, 0);
    vector<int> stk;
    int now = 0, cnt = 0;
    ll res = 0;
    auto tarjan = [&](auto &&self, int u, int fa) -> void {
        stk.push_back(u);
        dfn[u] = low[u] = now++;
        w[u] = 1;
        for (auto v : e[u]) {
            if (v == fa) continue;
            if (dfn[v] == -1) {
                self(self, v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    res = max(res, 1ll * w[v] * (n - w[v]));
                }
                w[u] += w[v];
            }
            else if (id[v] == -1) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            int v;
            do {
                v = stk.back();
                stk.pop_back();
                id[v] = cnt;
            } while (v != u);
            ++cnt;
        }
    };
    
    tarjan(tarjan, 0, -1);
    cout << n * (n - 1ll) / 2 - res << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}