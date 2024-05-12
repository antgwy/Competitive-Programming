#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k + 1, 0), b(k + 1, 0);
    for (int i = 1; i <= k; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        int ans;
        if (x == n) ans = b[k];
        else {
            int id = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;
            ans = b[id] + 1ll * (x - a[id]) * (b[id+1] - b[id]) / (a[id+1] - a[id]);
        }
        cout << ans << " \n"[i == q];
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