#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int x = a[1], res = n, lst = 0;
    for (int i = 2; i <= n; ++i) {
        if (a[i] != x) {
            res = min(res, i - lst - 1);
            lst = i;
        }
    }
    if (lst != 0) res = min(res, n - lst);
    if (res == n) cout << "-1\n";
    else cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}