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
    int h, w;
    cin >> h >> w;
    vector<vector<int> > s(h + 2, vector<int>(w + 2, 1));
    vector<vector<bool> > vis(h + 2, vector<bool>(w + 2, false));
    vector<array<int, 2> > dd{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
    for (int i = 1; i <= h; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < w; ++j) {
            if (str[j] == '#') {
                s[i][j+1] = 0; vis[i][j+1] = true;
                for (auto d : dd) {
                    int nx = i + d[0];
                    int ny = j + 1 + d[1];
                    if (s[nx][ny] == 1) s[nx][ny] = 2;
                }
            }
        }
    }

    set<pii> t;
    auto dfs = [&](auto self, int x, int y) -> int {
        int res = 1;
        vis[x][y] = true;
        for (auto d : dd) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && !vis[nx][ny]) {
                if (s[nx][ny] == 1) res += self(self, nx, ny);
                else t.emplace(nx, ny);
            }
        }
        return res;
    };

    int ans = 1;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (!vis[i][j] && s[i][j] == 1) {
                t.clear();
                ans = max(ans, dfs(dfs, i, j) + (int)t.size());
            }
        }
    }

    cout << ans << "\n";

    return 0;
}