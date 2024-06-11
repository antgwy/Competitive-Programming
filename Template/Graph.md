
# 图论

## LCA

## 网络流

## 点分治



## 强连通分量与 2-SAT

[944div4 H.](https://codeforces.com/contest/1971/problem/H)

```cpp
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
```