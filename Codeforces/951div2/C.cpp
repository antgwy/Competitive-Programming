#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

ll lcm(ll x, ll y) {
    return 1ll * x / __gcd(x, y) * y;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll l = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        l = lcm(l, a[i]);
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += 1ll * l / a[i];
    }
    if (l > sum) {
        for (int i = 0; i < n; i++) {
            cout << l / a[i] << " \n"[i == n - 1];
        }
    }  
    else cout << "-1\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}