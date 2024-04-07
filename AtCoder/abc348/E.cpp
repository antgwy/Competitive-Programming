#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

vector<vector<int> > adj;
vector<int> c;
vector<ll> dp, sum;
ll ans = LLONG_MAX;

// sum[i]: 关于顶点 i 子树顶点 x 的 c[x] 和
// dp[i]:  关于顶点 i 子树顶点 x 的 c[x] * d(i, x) 和
void dfs1(int v, int p = -1) {
    sum[v] = c[v];
    for (auto u : adj[v]) {
        if (u == p) continue;
        dfs1(u, v);
        sum[v] += sum[u];
        dp[v] += dp[u] + sum[u];
    }
}

// vw:  关于 v 子树以外顶点 x 的 c[x] 和
// vdp: 关于 v 子树以外顶点 x 的 c[x] * d(i, x) 和
void dfs2(int v, int p, ll vw, ll vdp) {
    ans = min(ans, dp[v] + vdp + vw);
    for (auto u : adj[v]) {
        if (u == p) continue;
        ll uw = vw + sum[v] - sum[u];
        ll udp = vdp + dp[v] - (dp[u] + sum[u]) + vw;
        dfs2(u, v, uw, udp);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    adj.resize(n, {});
    c.resize(n);
    dp.resize(n, 0);
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
    dfs2(0, -1, 0, 0);

    cout << ans << "\n";
    
    return 0;
}