#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1), dp(n + 1), sum(n + 1);
        for (int i = 0; i < n; ++i) cin >> p[i];
        stack<int> sta;
        dp[0] = 0;
        ll st_sum = 0;
        for (int i = 0; i < n; ++i) {
            while (!sta.empty() && p[sta.top()] > p[i]) { 
                st_sum -= dp[sta.top()];
                sta.pop(); 
            }
            int j = sta.empty() ? 0 : sta.top() + 1;
            dp[i] = (st_sum + sum[i] - sum[j] + sta.empty()) % MOD;
            sum[i+1] = (sum[i] + dp[i]) % MOD;
            st_sum = (st_sum + dp[i]) % MOD;
            sta.push(i);
        }
        cout << (st_sum + MOD) % MOD << "\n";
    }
    return 0;
}