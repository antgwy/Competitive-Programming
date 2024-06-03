#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) cin >> b[i];
    ll ans = 1;
    int lst = INF;
    for (int i = 0; i < n; i++) {
        if (min(a[i], b[i]) <= b[n] && b[n] <= max(a[i], b[i])) {
            lst = 0;
        }
        lst = min(lst, abs(a[i] - b[n]));
        lst = min(lst, abs(b[i] - b[n]));
        ans += abs(a[i] - b[i]);
    }
    cout << ans + lst << "\n";
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