class Solution {
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        int m = s.length();
        vector<vector<int> > memo(m, vector<int>(m, -1));
        auto dfs = [&](auto &&self, int i, int cnt, bool limit) -> int {
            if (i == m) return cnt;
            if (!limit && memo[i][cnt] >= 0) return memo[i][cnt];
            int res = 0;
            int up = limit ? s[i] - '0' : 9;
            for (int d = 0; d <= up; d++) {
                res += self(self, i + 1, cnt + (d == 1), limit && d == up);
            }
            if (!limit) memo[i][cnt] = res;
            return res;
        };
        return dfs(dfs, 0, 0, true);
    }
};