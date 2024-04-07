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
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (auto &l : g) cin >> l;
    int n;
    cin >> n;
    vector<vector<int> > e(h, vector<int>(w, -1));
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        cin >> e[x-1][y-1];
    }
    vector<vector<int> > vis(h, vector<int>(w, -1)); 
    vector<array<int, 2> > d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    P st, ed;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (g[i][j] == 'S') st = {i, j};
            else if (g[i][j] == 'T') ed = {i, j};
        }
    }

    auto valid = [&](int x, int y) {
        return (x >= 0 && y >= 0 && x < h && y < w && g[x][y] != '#');
    };

    auto bfs = [&](int sx, int sy) {
        queue<P> q;
        q.push({sx, sy});
        vis[sx][sy] = e[sx][sy];
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (vis[x][y] <= 0) continue;
            for (int i = 0; i < 4; ++i) {
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                if (!valid(nx, ny)) continue;

                int ne = max(e[nx][ny], vis[x][y] - 1);
                if (ne <= vis[nx][ny]) continue;

                vis[nx][ny] = ne;
                q.push({nx, ny});

                if (nx == ed.first && ny == ed.second) {
                    cout << "Yes\n";
                    exit(0);
                } 
            }
        }
        cout << "No\n";
    };
    bfs(st.first, st.second);
    return 0;
}