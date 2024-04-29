#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> px(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        px[i+1] = px[i] ^ a[i];
    } 
    ll res = 0;
    for (int k = 0; k < 30; k++) {
        int suf = 0;
        for (int i = 0; i <= n; i++) {
            suf += (px[i] >> k & 1);
        }
        int pre = 0;
        for (int i = 0; i < n; i++) {
            suf -= (px[i] >> k & 1);
            pre += (px[i] >> k & 1);
            if (k == __lg(a[i])) {
                res += 1ll * pre * suf + 1ll * (i + 1 - pre) * (n - i - suf);
            }
        }
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