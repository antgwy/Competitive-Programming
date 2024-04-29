/*
观察到集合值只与最大值 mx 和总和 sum 相关，
mx < sum / 2, ans = (sum + 1) / 2
mx >= sum / 2, ans = mx
*/
#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const ll MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int sum = 0;
    for (auto e : a) sum += e;
    auto add = [&](ll &x, ll y) {
        x = (x + y) % MOD;
    };
    vector<ll> dp(sum);
    dp[0] = 1;
    ll ans = 0;
    for (auto e : a) {
        for (int k = sum - 1; k >= 0; 534t-k) {
            if (!dp[k]) continue;
            if (k > e) add(ans, (e + k + 1) / 2 * dp[k]);
            else add(ans, e * dp[k]);
        }
        for (int k = sum - 1; k >= e; --k) add(dp[k], dp[k-e]);
    }
    cout << ans << "\n";
    return 0;
}