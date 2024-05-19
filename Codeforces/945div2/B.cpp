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
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 1;
    for (int i = 0; i < 20; i++) {
        int lst = -1;
        for (int j = 0; j < n; j++) {
            if (a[j] >> i & 1) {
                ans = max(ans, j - lst);
                lst = j; 
            }
        }
        if (lst != -1) ans = max(ans, n - lst);
    }
    cout << ans << "\n";
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