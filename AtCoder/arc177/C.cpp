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
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    
    auto bfs = [&](int st) -> int {
        priority_queue<pii, vector<pii>, greater<pii> > q;
        vector<vector<bool> > vis(n, vector<bool>(n, false));
        vector<vector<int> > dis(n, vector<int>(n, INF));
        vector<vector<int> > dd = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        if ((st == 0 && s[0][0] != 'B') || (st == n - 1 && s[0][n-1] != 'R')) dis[st/n][st%n] = 0;
        else dis[st/n][st%n] = 1;
        q.push({dis[st/n][st%n], st});
        while (!q.empty()) {
            auto [v, u] = q.top(); q.pop();
            int x = u / n, y = u % n;
            if (vis[x][y]) continue;
            vis[x][y] = true;
            for (auto d : dd) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                int f = ((st == 0 && s[nx][ny] != 'B') || (st == n - 1 && s[nx][ny] != 'R')) ? 0 : 1;
                if (dis[x][y] + f < dis[nx][ny]) {
                    dis[nx][ny] = min(dis[nx][ny], dis[x][y] + f);
                    q.push({dis[nx][ny], nx * n + ny});   
                }
            }
        }
        int ans = (st == 0) ? dis[n-1][n-1] : dis[n-1][0];
        return ans;
    };

    cout << bfs(0) + bfs(n - 1) << "\n";
    return 0;
}