/*
dp[i][j] max \sum_{k=1}^j(0.9)^{j-k}Q_k choosing j out of i
dp[i][j] = 
max(dp[i-1][1], p[i]) j = 1
max(dp[i-1][j], 0.9*dp[i-1][j-1]+p[i]) 2\le j\le i-1
0.9*dp[i-1][j-1]+p[i]
*/
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
    vector<double> p(n + 1);
    for (int i = 0; i < n; ++i) cin >> p[i];
	vector<double> dp(n + 1, 0);
	double c = 0.9;
    for (int i = 0; i < n; ++i) {
        dp[i+1] = c * dp[i] + p[i];
        for (int j = i - 1; j >= 0; --j) {
            dp[j+1] = max(c * dp[j] + p[i], dp[j+1]);
        }
    }
    double w = 0.0, ans = -1200.0;
    for (int i = 1; i <= n; ++i) {
        w = c * w + 1.0;
        ans = max(ans, dp[i]/w - 1200.0/sqrt((double)i));
    }
    cout << fixed << setprecision(7) << ans << "\n";
    return 0;
}