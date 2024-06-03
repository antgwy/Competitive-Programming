#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const ll MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll ans = 0, len, cyc, r;
    for (int i = 0; i < 60; i++) {
        if ((m >> i & 1) == 0) continue;
        ll bit = 1ll << i;
        len = bit << 1;
        cyc = (n + 1) / len;
        r = (n + 1) % len;
        ll cnt = cyc * bit + max(0ll, r - bit);
        cnt %= MOD;
        ans = (ans + cnt) % MOD;
    }
    cout << ans << "\n";
    return 0;
}