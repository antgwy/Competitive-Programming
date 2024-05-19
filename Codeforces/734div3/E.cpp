/*
dp[i]: 对前 i 个元素且保持最后一个元素固定的最大固定点数。
a[i] > i dp[i] = 0, 否则从 j < i 的 满足 i-a[i]>=j-a[j] and a[i]>a[j] 的 j 递推来。
*/
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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] > i) continue;
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (dp[j] && i - a[i] >= j - a[j] && a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (dp[i] >= k) ans = min(ans, i - a[i]);
    }
    if (ans == INT_MAX) ans = -1;
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