// dp[i][j] 前 i 个元素操作 j 次
#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll> > dp(n + 1, vector<ll>(k + 1, LLONG_MAX / 2));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int mi = a[i];
        for (int j = 0; i + j < n && j <= k; j++) {
            mi = min(mi, a[i+j]);
            for (int x = 0; x + j <= k; x++) {
                dp[i+j+1][x+j] = min(dp[i+j+1][x+j], dp[i][x] + 1ll * mi * (j + 1));
            }
        }
    }
    // debug(dp[n][k]);
    ll ans = *min_element(dp[n].begin(), dp[n].end());
    cout << ans << "\n";
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