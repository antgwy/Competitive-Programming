#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    bool f = true;
    if (s[0][0] != s[n-1][m-1]) {
        bool ok = false;
        for (int j = 0; j < m - 1; ++j) {
            if (s[0][j] != s[0][j+1] || s[n-1][j] != s[n-1][j+1]) {
                ok = true;
                break;
            }
        }
        if (!ok) f = false;

        ok = false;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i][0] != s[i+1][0] || s[i][m-1] != s[i+1][m-1]) {
                ok = true;
                break;
            }
        }
        if (!ok) f = false;
    }
    cout << (f ? "YES" : "NO") << "\n";
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