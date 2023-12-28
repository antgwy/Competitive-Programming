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
    int n, k;
    cin >> n >> k;
    vector<int> c(n + 1, 2);
    int x;
    for (int i = 1; i <= k; ++i) {
        cin >> x;
        c[x] = 1;
    }
    vector<int> a;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= c[i]; ++j) {
            a.push_back(i);
        }
    }
    int m = a.size();
    vector<int> l(m + 1), r(m + 1);
    for (int i = 2; i <= m; i += 2) l[i] = l[i-2] + (a[i-1] - a[i-2]);
    for (int i = m - 2; i >= 0; i -= 2) r[i] = r[i+2] + (a[i+1] - a[i]);
    if (m & 1) {
        int ans = INF;
        for (int i = 0; i < m; i += 2) {
            ans = min(ans, l[i] + r[i+1]);
        }
        cout << ans << "\n";
    }
    else cout << l[m] << "\n";
    return 0;
}