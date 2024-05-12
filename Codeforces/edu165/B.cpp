#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0, len = 0, f = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            len++;
        }
        else {
            if (len) ans += len + 1;
        }
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