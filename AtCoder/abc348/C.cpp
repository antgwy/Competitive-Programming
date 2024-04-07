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
    int n;
    cin >> n;
    unordered_map<int, int> c;
    int x, y;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        if (c.count(y)) c[y] = min(c[y], x);
        else c[y] = x;
    }
    int ans = 0;
    for (auto it = c.begin(); it != c.end(); ++it) {
        ans = max(ans, it->second);
    }
    cout << ans << "\n";
    return 0;
}