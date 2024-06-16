#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a >= b) {
        cout << 1ll * n * a << "\n";
        return;
    }
    int ed = min(n, b - a + 1);
    ll ans = 1ll * (b + (b - ed + 1)) * ed / 2 + 1ll * (n - ed) * a;
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