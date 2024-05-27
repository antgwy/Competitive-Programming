#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int m;
    ll x;
    cin >> m >> x;
    vector<int> c(m), h(m);
    int s = 0;
    for (int i = 0; i < m; i++) {
        cin >> c[i] >> h[i];
        s += h[i];
    }  
    vector<ll> dp(s + 1, LLONG_MAX / 2);
    dp[0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = s; j >= h[i]; j--) {
            if (dp[j-h[i]] + c[i] <= 1ll * i * x) {
                dp[j] = min(dp[j], dp[j-h[i]] + c[i]);
            }
        } 
    }
    int ans = 0;
    for (int i = s; i >= 0; i--) {
        if (dp[i] != LLONG_MAX / 2) {
            ans = i;
            break;
        }
    }
    /*
    vector<pair<ll, int> > dp(m);
    dp[0][x] = 0;
    if (!c[0]) dp[0][x] = h[0];
    int ans = dp[0][x];
    for (int i = 1; i < m; i++) {
        dp[i][x*(i+1)] = 0;
        for (int j = 0; j < i; j++) {
            for (auto [k, v] : dp[j]) {
                ll own = k + 1ll * (i - j - 1) * x;
                if (own >= c[i])  {
                    // if (!dp[i].count(own-c[i]+x)) dp[i][own-c[i]+x] = 0;
                    dp[i][own-c[i]+x] = max(dp[i][own-c[i]+x], v + h[i]);
                    ans = max(ans, dp[i][own-c[i]+x]);
                }
            }
        }
    }*/
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