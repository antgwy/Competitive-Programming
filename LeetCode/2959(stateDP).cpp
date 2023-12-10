class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        const int INF = 0x3f3f3f3f;
        vector<vector<int> > g(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) g[i][i] = 0;
        for (auto &e : roads) {
            int x = e[0], y = e[1], z = e[2];
            g[x][y] = min(g[x][y], z);
            g[y][x] = min(g[y][x], z);
        }

        vector<vector<int>> f(n);
        auto solve = [&](int sta) {
            vector<int> subset;
            for (int i = 0; i < n; ++i) {
                if ((sta >> i) & 1) {
                    f[i] = g[i];
                    subset.push_back(i);
                }
            }
            for (int k = 0; k < n; ++k) {
                if (!((sta >> k) & 1)) continue;
                for (int i = 0; i < n; ++i) {
                    if (!((sta >> i) & 1)) continue;
                    for (int j = 0; j < n; ++j) {
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                    }
                } 
            }
            for (int u : subset) {
                for (int v : subset) {
                    if (u == v) continue;
                    if (f[u][v] > maxDistance) return false;
                }
            }
            return true;
        };

        int ans = 0;
        for (int i = 0; i < (1 << n); ++i) {
            ans += solve(i);
        }
        return ans;
    }
};