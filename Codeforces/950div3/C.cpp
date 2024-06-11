#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    map<int, int> req;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!req.count(x)) req[x] = 0;
        if (a[i] != x) req[x]++;
    }
    cin >> m;
    bool f = true;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (req.count(x)) {
            f = true;
            if (req[x] > 0) req[x]--;
        }
        else f = false;
    }    
    for (auto [u, v] : req) {
        if (v) { f = false; break; }
    }
    cout << (f ? "YES" : "NO") << "\n";
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