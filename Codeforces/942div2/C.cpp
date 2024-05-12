#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll left = LLONG_MAX, right = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        left = min(left, a[i]);
        right = max(right, a[i]);
    }
    right = right + k + 1;

    auto check = [&](ll x) -> bool {
        ll res = 0;
        for (int i = 0; i < n; i++) {
            res += max((ll)0, x - a[i]);
        }
        return res <= k;
    };

    while (left < right) {
        ll mid = (left + right) / 2;
        if (check(mid)) left = mid + 1;
        else right = mid;
    }

    ll x = left - 1;
    
    for (int i = 0; i < n; i++) {
        k -= max((ll)0, x - a[i]);
    }
    /*
    vector<ll> b(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        b[i] = a[i%n];
    }
    ll l = 0, r = 0, mx = 0, cnt = 0;
    while (r < 2 * n) {
        if (b[r] <= x) cnt++;
        while (cnt > k) {
            if (b[l] <= x) cnt--;
            l++;
        }
        mx = max(mx, r - l + 1);
        r++;
    }
    debug(x); debug(mx);
    */
    ll mx = k;
    for (int i = 0; i < n; i++) mx += (a[i] > x);
    cout << x * (mx + 1) + (x - 1) * (n - mx - 1) << "\n";
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