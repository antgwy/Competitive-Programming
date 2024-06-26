#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

struct TwoSat {
    int n;
    vector<vector<int> > e;
    vector<bool> ans;
    TwoSat(int n) : n(n), e(2 * n), ans(n) {}
    void add_clause(int u, int v, int f, int g) {
        e[2*u+!f].push_back(2*v+g);
        e[2*v+!g].push_back(2*u+f);
    }
    bool satisfiable() {
        vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
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
        for (int i = 0; i < 2 * n; i++)
            if (dfn[i] == -1) tarjan(tarjan, i);

        for (int i = 0; i < n; i++) {
            if (id[2*i] == id[2*i+1]) return false;
            ans[i] = ans[2*i] > ans[2*i+1];
        }
        return true;
    }
    vector<bool> answer() { return ans; }
};

void solve() {
    int n;
    cin >> n;
    TwoSat ts(n);
    vector<int> a[3];
    for (int i = 0; i < 3; i++) {
        a[i].resize(n);
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = j + 1; k < 3; k++) {
                bool f = a[j][i] > 0, g = a[k][i] > 0;
                int x = abs(a[j][i]) - 1;
                int y = abs(a[k][i]) - 1;
                ts.add_clause(x, y, f, g);
            }
        }
    } 

    cout << (ts.satisfiable() ? "Yes" : "No") << "\n";
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