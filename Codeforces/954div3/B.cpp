#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mx = 0;
            if (i) mx = max(mx, a[i-1][j]);
            if (j) mx = max(mx, a[i][j-1]);
            if (i != n - 1) mx = max(mx, a[i+1][j]);
            if (j != m - 1) mx = max(mx, a[i][j+1]);
            a[i][j] = min(a[i][j], mx);
            cout << a[i][j] << " \n"[j == m - 1];
        }
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