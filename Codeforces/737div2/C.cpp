// https://codeforces.com/blog/entry/93703?#comment-827127
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;

ll qpow(ll x, ll y, const ll &mod = MOD) {
    ll ret = mod != 1;
    for (x %= mod; y; y >>= 1, x = x * x % mod)
        if (y & 1) ret = ret * x % mod;
    return ret; 
}

void solve() {
    int n, k;
    cin >> n >> k;
    ll res = 0, bit = qpow(2, n - 1);
    if (n & 1) {
        res = qpow(bit + 1, k);
    }
    else {
        /*for (int i = 0; i < k; i++) {
            (res += qpow(bit - 1, i) * qpow(2 * bit, k - i - 1)) %= MOD;
        }*/
        res = ((qpow(2 * bit, k) - qpow(bit - 1, k) + MOD) % MOD) * qpow(bit + 1, MOD - 2, MOD) % MOD;
        (res += qpow(bit - 1, k)) %= MOD;
    }
    cout << res << "\n";
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