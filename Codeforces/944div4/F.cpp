#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;

vector<ll> sq(N);

void solve() {
    ll r;
    cin >> r;   
    ll x = r * r, y = (r + 1) * (r + 1);
    ll l = sqrt(x / 2);
    while (2 * l * l < x) l++;
    ll ans = 0;
    for (ll i = l; i <= r; i++) {
        ll ub = sqrt(y - i * i);
        while (i * i + ub * ub >= y) ub--;
        ub = min(ub, i);
        ll lb = sqrt(x - i * i);
        while (i * i + lb * lb < x) lb++;

        if (!lb) {
            if (ub < i) ans += 8 * ub + 4;
            else ans += 8 * ub;
        }
        else {
            if (ub < i) ans += 8 * (ub - lb + 1);
            else ans += 8 * (ub - lb + 1) - 4;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    for (int i = 0; i < N; i++) sq[i] = 1ll * i * i;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}