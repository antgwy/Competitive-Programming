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
    vector<vector<int> > e(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        e[i].push_back(a[i]);
    }

    vector<int> id(n, -1), dfn(n, -1), low(n, -1);
    vector<int> stk;
    int now = 0, cnt = 0;
    auto tarjan = [&](auto &&self, int u) -> void {
        stk.push_back(u);
        dfn[u] = low[u] = now++;
        for (auto v : e[u]) {
            if (dfn[v] == -1) {
                self(self, v);
                low[u] = min(low[u], low[v]);
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
    for (int i = 0; i < n; i++)
        if (dfn[i] == -1) tarjan(tarjan, i);
    
    e.assign(cnt, vector<int>());
    vector<int> sz(cnt, 0), ind(cnt, 0);
    for (int i = 0; i < n; i++) {
        sz[id[i]]++;
        if (id[i] == id[a[i]]) continue;
        e[id[a[i]]].push_back(id[i]);
        ind[id[i]]++;
    }

    vector<int> f(cnt, 0);
    queue<int> q;
    for (int i = 0; i < cnt; i++) {
        if (ind[i]) continue;
        q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : e[u]) {
            f[v] += f[u] + sz[u];
            if (--ind[v] == 0) {
                q.push(v);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < cnt; i++) ans += f[i] + 1ll * sz[i] * sz[i];
    cout << ans << "\n";
    return 0;
}