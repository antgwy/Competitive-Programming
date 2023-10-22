#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int N = 1005;

int h, w;
string s[N];
bool vis[N][N];
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};

void dfs(int x, int y) {
    if (x < 1 || x > h || y < 1 || y > w || vis[x][y] || s[x][y] != '#') {
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 8; ++i) {
        int cx = x + dx[i], cy = y + dy[i];
        dfs(cx, cy);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w;
    for (int i = 1; i <= h; ++i) {
        cin >> s[i]; s[i] = " " + s[i];
    }
    int cnt = 0;
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (s[i][j] == '#' && !vis[i][j]) {
                dfs(i, j);
                cnt++;
                // cout << "i j:" << i << " " << j << "\n";
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
