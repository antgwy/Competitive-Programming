#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> p, dp(N, 0);
    for (int i = 2; i < 32; ++i) {
        int x = 0;
        for (int j = 4; j >= 0; --j) {
            x = 10 * x + ((i >> j) & 1);
        }
        p.push_back(x);
    }
    dp[1] = 1;
    for (auto x : p) {
        for (int y = 1; y * x < N; ++y) {
            dp[y*x] |= dp[y];
        }
    }
    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n] ? "YES" : "NO") << "\n";
    }
    return 0;
}