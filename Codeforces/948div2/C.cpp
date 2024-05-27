#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll x = 1;
    for (int i = 0; i < n; i++) {
        x = lcm(x, 1ll * a[i]);
        if (x > 1e9) break;
    }
    auto it = find(a.begin(), a.end(), x);
    if (it == a.end()) {
        cout << n << "\n";
        return;
    }

    int ans = 0;
    auto check = [&](int d) {
        if (find(a.begin(), a.end(), d) != a.end()) return;
        int l = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (d % a[i] == 0) {
                l = lcm(l, a[i]);
                cnt++;
            }
        }
        if (l == d) ans = max(ans, cnt);
    };

    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            check(d);
            check(x / d);
        }
    }
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