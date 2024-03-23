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
    int n, H, W;
    cin >> n >> H >> W;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<vector<int> > f(H, vector<int>(W));
    vector<bool> vis(n);

    auto canPlace = [&](int x, int y, int h, int w) {
        if (x + h > H || y + w > W) return false;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (f[x+i][y+j]) return false;
            }
        }
        return true;
    };

    auto setTile = [&](int x, int y, int h, int w, int val) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                f[x+i][y+j] = val;
            }
        }
    };

    auto dfs = [&](auto self, int x, int y) -> void {
        if (x == H) {
            cout << "Yes\n";
            exit(0);
        }
        if (y == W) return self(self, x + 1, 0);
        if (f[x][y]) return self(self, x, y + 1);
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            vis[i] = true;
            for (int t = 0; t < 2; ++t) {
                if (canPlace(x, y, a[i], b[i])) {
                    setTile(x, y, a[i], b[i], 1);
                    self(self, x, y + 1);
                    setTile(x, y, a[i], b[i], 0);
                }
                swap(a[i], b[i]);
            }
            vis[i] = false;
        }
    };
    dfs(dfs, 0, 0);
    cout << "No\n";
    return 0;
}