// https://atcoder.jp/contests/arc178/editorial/10051
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const ll MOD = 998244353;

ll qpow(ll x, ll y, const ll &mod = MOD) {
    ll ret = mod != 1;
    for (x %= mod; y; y >>= 1, x = x * x % mod)
        if (y & 1) ret = ret * x % mod;
    return ret; 
}

void solve() {
    ll i, j, k;
    cin >> i >> j >> k;
    

    function<ll(ll, ll, ll)> calc = [&](ll i, ll j, ll k) -> ll {
        if (i > j) swap(i, j);
        if (k > j + 1 || k < j) return 0;
        
        ll a = qpow(10, i - 1), b = qpow(10, j - 1);
        ll inv = qpow(2, MOD - 2), ret;
        if (j + 1 == k) {
            ret = 81 * qpow(10, i + j - 2) % MOD;
            ret = (ret - calc(i, j, j) + MOD) % MOD;
        }
        else if (i == j) {
            ll x = 8 * a % MOD;
            ret = ((x * (x + 1) % MOD) * inv) % MOD;
        }
        else {
            ret = (9 * a % MOD) * ((9 * b % MOD - ((11 * a - 1) % MOD * inv % MOD) + MOD) % MOD) % MOD;
        }
        return ret;
    };
    
    cout << calc(i, j, k) << "\n";
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