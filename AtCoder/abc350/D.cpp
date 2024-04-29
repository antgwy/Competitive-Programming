#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> fa(n + 1), sz(n + 1, 1);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    
    auto find = [&](auto self, int x) -> int {
        if (fa[x] == x) return x;
        return fa[x] = self(self, fa[x]);
    };

    auto unite = [&](int x, int y) {
        int fx = find(find, x), fy = find(find, y);
        if (fx == fy) return;
        fa[fx] = fy; 
        sz[fy] += sz[fx];
    };

    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        unite(x, y);
    }

    ll cnt = 0;
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        int rt = find(find, i);
        if (!vis[rt]) {
            vis[rt] = true;
            cnt += 1ll * sz[rt] * (sz[rt] - 1) / 2;
        }
    }

    cout << cnt - m << "\n";
    return 0;
}