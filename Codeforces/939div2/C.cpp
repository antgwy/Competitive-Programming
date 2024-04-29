#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += (2 * i - 1) * i;
    cout << ans << " " << 2 * n << "\n";
    for (int i = n; i >= 1; --i) {
        cout << "1 " << i << " ";
        for (int j = 1; j <= n; j++) cout << j << " \n"[j == n];
        cout << "2 " << i << " ";
        for (int j = 1; j <= n; j++) cout << j << " \n"[j == n];
    }
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