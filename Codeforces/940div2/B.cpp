#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) { cout << k << "\n"; return; }
    int x = ((1 << (31 - __builtin_clz(k))) - 1);
    cout << x << " " << k - x << " \n"[n <= 2];
    for (int i = 3; i <= n; ++i) {
        cout << 0 << " \n"[i == n];
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