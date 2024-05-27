#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

struct DSU {
    vector<int> fa, sz;
    DSU() {}
    DSU(int n) { init(n); }
    void init(int n) {
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        sz.assign(n, 1);
    }
    int find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
    int size(int x) {
        return sz[find(x)];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int u, v, w;
    vector<DSU> dsu(10, DSU(n));
    vector<int> cnt(10, n);
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        u--; v--;
        for (int j = w; j <= 10; j++) {
            cnt[j-1] -= dsu[j-1].merge(u, v);
        }
    }
    while (q--) {
        cin >> u >> v >> w;
        u--; v--;
        for (int j = w; j <= 10; j++) {
            cnt[j-1] -= dsu[j-1].merge(u, v);
        }
        int mst = 0, lst = n;
        for (int j = 1; j <= 10; j++) {
            mst += j * (lst - cnt[j-1]);
            lst = cnt[j-1];
        }
        cout << mst << "\n";
    }
    return 0;
}