
# 图论

## LCA

## 网络流

## 点分治


## 连通性

* 有向图强连通分量缩点

```cpp
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
            // if (low[v] >= dfn[u]) 割点
            // if (low[v] > dfn[u]) 割边 cnt(id == 0) < n
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

vector<vector<int> > ce(cnt);
vector<int> sz(cnt, 0), ind(cnt, 0);
for (int i = 0; i < n; i++) {
    sz[id[i]]++;
    for (auto j : e[i]) {
        if (id[i] == id[j]) continue;
        ce[id[i]].push_back(id[j]);
        ind[id[j]]++;
    }
}
```

* 边双连通分量

```cpp
struct EBCC {
    int n;
    vector<vector<int> > adj;
    vector<int> stk;
    vector<int> dfn, low, id;
    int now, cnt;
    
    EBCC() {}
    EBCC(int n) { init(n); }

    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        id.assign(n, -1);
        stk.clear();
        now = cnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void dfs(int x, int p) {
        dfn[x] = low[x] = now++;
        stk.push_back(x);
        for (auto y : adj[x]) {
            if (y == p) continue;
            if (dfn[y] == -1) {
                dfs(y, x);
                low[x] = min(low[x], low[y]);
            } else if (id[y] == -1) {
                low[x] = min(low[x], dfn[y]);
            }
        }
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                id[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }
    
    vector<int> work() {
        dfs(0, -1);
        return id;
    }
    
    struct Graph {
        int n;
        vector<pair<int, int> > edges;
        vector<int> siz;
        vector<int> cnte;
    };
    Graph compress() {
        Graph g;
        g.n = cnt;
        g.siz.resize(cnt);
        g.cnte.resize(cnt);
        for (int i = 0; i < n; i++) {
            g.siz[id[i]]++;
            for (auto j : adj[i]) {
                if (id[i] < id[j]) {
                    g.edges.emplace_back(id[i], id[j]);
                } else if (i < j) {
                    g.cnte[id[i]]++;    // 存与比 i 大的节点连边数
                }
            }
        }
        return g;
    }
};
```

边双连通分量有重边时用链式前向星。

```cpp
void add(int x, int y) {
    ver[tot] = y, nxt[tot] = head[x], head[x] = tot++;
}

void tarjan(int x, int pre) {
    dfn[x] = low[x] = ++now;
    stk.push_back(x);
    for (int i = head[x]; i != -1; i = nxt[i]) {
        int y = ver[i];
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x]) {
                bridge[i] = bridge[i^1] = true;
            }
        }
        else if (i != (pre ^ 1)) low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x]) {
        int y;
        ++cnt;
        do {
            y = stk.back();
            stk.pop_back();
            id[y] = cnt;  
        } while (y != x);
    }
}
```


* 2-SAT

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
