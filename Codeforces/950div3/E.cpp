#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m, 0));
    auto b = a;
    vector<int> row(n * m), col(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
            row[a[i][j]] = i;
            col[a[i][j]] = j;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            b[i][j]--;
        }
    }

    for (int i = 0; i < n; i++) {
        int r = row[b[i][0]];
        swap(a[i], a[r]);
        for (int j = 0; j < m; j++) {
            row[a[i][j]] = i;
            row[a[r][j]] = r;
        }
    }

    for (int j = 0; j < m; j++) {
        int c = col[b[0][j]];
        for (int i = 0; i < n; i++) {
            swap(a[i][c], a[i][j]);
            col[a[i][j]] = j;
            col[a[i][c]] = c;
        }
    }
    cout << (a == b ? "YES" : "NO") << "\n";
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