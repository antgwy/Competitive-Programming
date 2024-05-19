#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<int> dp(1<<n, 0);
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask >> i & 1)) continue;
            for (int j = i + 1; j < n; j++) {
                if (!(mask >> j & 1)) continue;
                if (a[i] != a[j] && b[i] != b[j]) continue;
                dp[mask] |= 1 ^ dp[mask^(1<<i)^(1<<j)];
            }
        } 
    }
    cout << (dp.back() ? "Takahashi" : "Aoki") << "\n";
    return 0;
}