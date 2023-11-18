// dp[i][j] s 前 i 匹配 t 前 j
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
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int> > dp(n + 1, vector<int>(10));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k < m; ++k) {
                if (s[i] == t[k] && (k == j || k == 0 || j == m)) {
                    dp[i+1][k+1] |= dp[i][j];
                }
            }
        }
    }
    if (dp[n][m]) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}