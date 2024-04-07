#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<string> g(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i] >> w[i];
    }
    vector<int> e(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i] == g[j] || w[i] == w[j]) {
                e[i] |= 1 << j;
            }
        }
    }
    vector<int> dp(1 << n);
    for (int i = 0; i < n; ++i) dp[1<<i] |= 1 << i;
    int ans = 0;
    for (int s = 1; s < (1 << n); s++) {
        if (dp[s]) ans = max(ans, __builtin_popcount(s));
        for (int i = 0; i < n; ++i) {
            if ((~s >> i & 1) && (dp[s] & e[i]))
                dp[s|1<<i] |= 1 << i;
        }
    }
    cout << n - ans << "\n";
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