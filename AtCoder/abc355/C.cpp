#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<int> r(t + 1), c(t + 1);
    int ans = -1;
    for (int i = 1; i <= t; i++) {
        int u;
        cin >> u;
        u--;
        r[u/n]++;
        c[u%n]++;
        if (u / n == u % n) r[n]++;
        if (u / n + u % n == n - 1) c[n]++;
        if (ans != -1) continue;
        if (r[u/n] == n || c[u%n] == n || r[n] == n || c[n] == n) ans = i;
    }
    cout << ans << "\n";
    return 0;
}