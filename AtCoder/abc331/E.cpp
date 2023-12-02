#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n), b(m);
    for (int &e : a) cin >> e;
    for (int &e : b) cin >> e;
    vector<int> idx(m);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return b[i] == b[j] ? i < j : b[i] < b[j];
    });
    reverse(idx.begin(), idx.end());
    vector<vector<int> > g(n);
    for (int i = 0; i < l; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
    }
    vector<int> ok(m, 1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j : g[i]) { ok[j] = 0; }
        for (int j : idx) {
            if (!ok[j]) continue;
            ans = max(ans, a[i] + b[j]);
            break;
        }
        for (int j : g[i]) { ok[j] = 1; }
    }
    cout << ans << "\n";
    return 0;
}