/*
运动的相对性，石头静止，机器人和终点每秒向下运动，三个方向：不动，下下，右下。
*/
#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

int t, n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int> > a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        queue<P> q; 
        vector<vector<int> > dp(n, vector<int>(m, -1));
        q.emplace(0, 0);
        dp[0][0] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (!a[(x+1)%n][y] && !a[(x+2)%n][y] && dp[(x+2)%n][y] == -1) {
                dp[(x+2)%n][y] = dp[x][y] + 1;
                q.emplace((x + 2) % n, y);
            }
            if (y < m - 1 && !a[(x+1)%n][y+1] && dp[(x+1)%n][y+1] == -1) {
                dp[(x+1)%n][y+1] = dp[x][y] + 1;
                q.emplace((x + 1) % n, y + 1);            
            }
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int tmp = dp[i][m-1];
            if (~tmp) {
                if (tmp % n != (i + 1) % n) {
                    tmp += (i + 1 - tmp % n + n) % n;
                }
                if (ans == -1 || ans > tmp) ans = tmp;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}