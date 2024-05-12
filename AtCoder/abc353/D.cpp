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
    vector<ll> a(n + 1, 0), pa(n + 1, 0), pb(n + 1, 0);

    auto ilen = [&](int x) {
        ll res = 1;
        for (; x; x /= 10)
            res *= 10;
        return res;
    };

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pa[i] = (pa[i-1] + a[i]) % MOD;
        pb[i] = (pb[i-1] + ilen(a[i])) % MOD;
    }   

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += (ll)a[i] * (pb[n] - pb[i] + MOD) % MOD + (pa[n] - pa[i] + MOD) % MOD;
        ans = (ans + MOD) % MOD;  
    }
    cout << ans << "\n";
    return 0;
}