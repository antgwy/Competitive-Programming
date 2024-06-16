#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == n - 1) {
            cout << x + mx << "\n";
            return;
        }
        mx = max(mx, x);
    }
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