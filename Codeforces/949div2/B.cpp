#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int hbit(int x) { return 1 << (31 - __builtin_clz(x)); }

void solve() {
    int n, m;
    cin >> n >> m;
    int res = (n + m) - hbit(n + m), lst = n + m;
    if (!m) { cout << n << "\n"; return; }
    while (res >= 2 * m) {
        lst = res;
        res = res - hbit(res);
    }
    cout << ((n + m) | (hbit(lst) - 1)) << "\n";
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