#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m;
    string s, c;
    cin >> n >> m >> s;
    vector<bool> id(n, false);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        id[x-1] = true;
    }
    cin >> c;
    sort(c.begin(), c.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (id[i]) {
            s[i] = c[cnt++];
        }
    }
    cout << s << "\n";
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