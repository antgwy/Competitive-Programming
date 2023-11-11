#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int N = 10, M = 105;

int n, m, fa[N], p[N];
ll k, d[N][N];
ll ans = (ll)1e19;;

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

bool valid() {
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= n; ++i) {
        if (find(p[i]) == find(i)) return false;
        fa[find(i)] = find(p[i]);
    }
    return true;
}

void dfs(int x, ll sum) {
    if (x == n) {
        if (valid()) ans = min(ans, sum);
        return;
    }
    for (int y = 1; y <= n; ++y) {
        if (y == x || d[x][y] == -1) continue;
        p[x] = y;
        dfs(x + 1, (sum + d[x][y]) % k);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    int x, y; ll z;
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> z;
        d[x][y] = d[y][x] = z;     
    }
    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}