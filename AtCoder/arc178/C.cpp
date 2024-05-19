// https://atcoder.jp/contests/arc178/editorial/10052
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
    int n, l;
    cin >> n >> l;
    const int M = 2e5 + 1;
    vector<int> dp(M, INF);
    dp[0] = 0;
    for (int k = 1; k < l; k++) {
        int w = k * (l - k);
        if (w > M) break;
        for (int i = w; i < M; i++) {
            dp[i] = min(dp[i], dp[i-w] + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cout << (dp[x] == INF ? -1 : dp[x]) << "\n";
    }
    return 0;
}