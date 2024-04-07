#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

vector<vector<int> > adj;
vector<int> c;
vector<ll> sum;
ll ans = 0;

void dfs1(int v, int p = -1) {
    sum[v] = c[v];
    for (auto u : adj[v]) {
        if (u == p) continue;
        dfs1(u, v);
        sum[v] += sum[u];
    }
}

int dfs2(int v, int p) {
    for (auto u : adj[v]) {
        if (u == p || 2 * sum[u] <= sum[0]) continue;
        return dfs2(u, v);
    }
    return v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    adj.resize(n, {});
    c.resize(n);
    sum.resize(n, 0);

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for (int i = 0; i < n; ++i) cin >> c[i];

    dfs1(0);
    int x = dfs2(0, -1);
    dfs1(x);

    for (int i = 0; i < n; ++i) {
        if (i != x) {
            ans += sum[i];
        }
    }
    cout << ans << "\n";
    
    return 0;
}