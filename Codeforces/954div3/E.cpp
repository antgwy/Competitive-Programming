#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const ll inf = LLONG_MAX / 2;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    map<int, vector<int> > c;
    for (int i = 0; i < n; i++) {
        c[a[i]%k].push_back(i);
    }
    
    int valid = 1;
    if (n % 2 == 0) valid = 0;

    ll ans = 0;
    for (auto [_, v] : c) {
        int m = v.size();

        if (m & 1) {
            valid--;
            if (valid < 0) { cout << "-1\n"; return; }
        }

        vector<ll> pre(m / 2 + 1, 0), suf(m / 2 + 1, 0);
        for (int i = 0; i + 1 < m; i += 2) {
            pre[i/2+1] = pre[i/2] + (a[v[i+1]] - a[v[i]]) / k;
        }
        for (int i = m - 1; i >= 1; i -= 2) {
            suf[(m-i)/2+1] = suf[(m-i)/2] + (a[v[i]] - a[v[i-1]]) / k;
        }

        if (m % 2 == 0) {
            ans += pre[m/2];
            continue;
        }

        ll res = inf;
        for (int i = 0; i <= m / 2; i++) {
            res = min(res, pre[i] + suf[m/2-i]);
        }
        ans += res;
    }
    cout << ans << "\n";
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