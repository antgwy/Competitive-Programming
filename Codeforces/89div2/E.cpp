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
    vector<vector<int> > e(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    int now = 0, cnt = 0;
    vector<int> dfn(n, -1), low(n, -1), id(n, -1), stk;
    vector<pii> ans;
    auto tarjan = [&](auto &&self, int u, int fa) -> void {
        dfn[u] = low[u] = now++;
        stk.push_back(u);
        for (int v : e[u]) {
            if (v == fa) continue;
            if (dfn[v] == -1) {
                self(self, v, u);
                low[u] = min(low[u], low[v]);
                ans.emplace_back(u, v);
            }
            else if (id[v] == -1) {
                low[u] = min(low[u], dfn[v]);
                if (dfn[v] < dfn[u]) ans.emplace_back(u, v);
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
    if (count(id.begin(), id.end(), 0) < n) {
        cout << "0\n";
    }
    else {
        for (auto [x, y] : ans) {
            cout << x + 1 << " " << y + 1 << "\n";
        }
    }

    return 0;
}