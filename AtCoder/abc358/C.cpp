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
    vector<int> f(n, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'o') f[i] |= (1 << j);
        }
    }
    int ans = n;
    for (int mask = 1; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (!(mask >> i & 1)) continue;
            sum |= f[i];
        }
        if (sum != ((1 << m) - 1)) continue;
        ans = min(ans, __builtin_popcount(mask));
    }
    cout << ans << "\n";
    return 0;
}