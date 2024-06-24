class Solution {
    using ll = long long;
    const int MOD = 1e9 + 7;
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<int> req(n, -1);
        int m = 0;
        for (auto &r : requirements) req[r[0]] = r[1], m = max(m, r[1]);
        vector<int> f(m + 1);
        f[0] = 1;
        for (int i = 1; i < n; i++) {
            int mx = req[i] < 0 ? m : req[i];
            int r = req[i-1];
            if (r >= 0) {
                int tmp = f[r];
                fill(f.begin(), f.end(), 0);
                fill(f.begin() + r, f.begin() + min(i + r, mx) + 1, tmp);
                continue;
            }
            for (int j = 1; j <= mx; j++) {
                f[j] = (f[j] + f[j-1]) % MOD;           // 前缀和
            }
            for (int j = mx; j > i; j--) {
                f[j] = (f[j] - f[j-i-1] + MOD) % MOD;   // 子数组计算 
            }
        }
        return f[req[n-1]];
    }
};
/*
class Solution {
    using ll = long long;
    const int MOD = 1e9 + 7;
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<int> req(n, -1);
        int m = 0;
        for (auto &r : requirements) req[r[0]] = r[1], m = max(m, r[1]);
        vector<vector<int> > f(n, vector<int>(m + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i < n; i++) {
            int l = 0, r = m;
            if (req[i] != -1) l = r = req[i];
            for (int j = l; j <= r; j++) {
                for (int k = 0; k <= min(i, j); k++) {
                    f[i][j] = ((ll)f[i][j] + f[i-1][j-k]) % MOD;
                }
            }
        }
        return f[n-1][req[n-1]];
    }
};
*/