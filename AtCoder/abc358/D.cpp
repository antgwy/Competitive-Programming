#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int st = lower_bound(a.begin(), a.end(), b[0]) - a.begin();
    ll ans = 0, tot = 0;
    for (int i = st; i < n && tot < m; i++) {
        if (a[i] >= b[tot]) {
            tot++;
            ans += a[i];
        }
    }
    if (tot == m) cout << ans << "\n";
    else cout << "-1\n";
    return 0;
}