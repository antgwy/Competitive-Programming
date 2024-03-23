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
    unordered_map<int, int> vis;
    ll ans = 1ll * k * (k + 1) / 2;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (vis.find(x) != vis.end()) continue;
        vis[x] = 1;
        if (x <= k) ans -= x;
    }
    cout << ans << "\n";
    return 0;
}