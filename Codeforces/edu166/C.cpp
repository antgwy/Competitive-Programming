#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + m + 1), b(n + m + 1), idx(n + m + 1);
    for (int i = 0; i <= n + m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n + m; i++) {
        cin >> b[i];
    }
    ll sa = 0, sb = 0;
    int ca = 0, cb = 0, p1 = -1, p2 = -1;
    for (int i = 0; i <= n + m; i++) {
        if (a[i] > b[i]) {
            if (ca < n) {
                sa += a[i];
                ca++;
                idx[i] = 0;
            }
            else if (cb < m) {
                if (p1 == -1) p1 = i;
                sb += b[i];
                cb++;
                idx[i] = 1;
            } 
        }
        else {
            if (cb < m) {
                sb += b[i];
                cb++;
                idx[i] = 1;
            }
            else if (ca < n) {
                if (p2 == -1) p2 = i;
                sa += a[i];
                ca++;
                idx[i] = 0;
            }
        }
    }
    vector<ll> ans(n + m + 1);
    for (int i = 0; i < n + m; i++) {
        if (idx[i] == 0) {
            ans[i] = sa + sb - a[i];
            if (i < p1) ans[i] = ans[i] + a[p1] - b[p1] + b[n+m];
            else ans[i] = ans[i] + a[n+m];
        }
        else {
            ans[i] = sa + sb - b[i];
            if (i < p2) ans[i] = ans[i] + b[p2] - a[p2] + a[n+m];
            else ans[i] = ans[i] + b[n+m];
        }
    }
    ans[n+m] = sa + sb;
    for (int i = 0; i <= n + m; i++) {
        cout << ans[i] << " \n"[i == n + m];
    }
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