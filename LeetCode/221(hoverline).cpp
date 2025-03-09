class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > h(m, vector<int>(n, -1));
        auto l = h, r = h;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    l[i][j] = r[i][j] = j;
                    h[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1' && matrix[i][j-1] == '1')
                    l[i][j] = l[i][j-1];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = n - 2; j >= 0; j--) {
                if (matrix[i][j] == '1' && matrix[i][j+1] == '1')
                    r[i][j] = r[i][j+1];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i && matrix[i][j] == '1' && matrix[i-1][j] == '1') {
                    l[i][j] = max(l[i][j], l[i-1][j]);
                    r[i][j] = min(r[i][j], r[i-1][j]);
                    h[i][j] = h[i-1][j] + 1;
                }
                int len = min(r[i][j] - l[i][j] + 1, h[i][j]);
                if (len > 0) ans = max(ans, len * len);
            }
        }

        return ans;
    }
};
/*
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > s(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + matrix[i-1][j-1] - '0';
            }
        }

        auto check = [&](int m, int n, int x) {
            for (int i = 0; i <= m - x; i++) {
                for (int j = 0; j <= n - x; j++) {
                    int x1 = i + 1, y1 = j + 1;
                    int x2 = x1 + x - 1, y2 = y1 + x - 1;
                    int sum = s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
                    if (sum == x * x) return true;
                }
            }
            return false;
        };

        int l = 0, r = min(m, n) + 1;

        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(m, n, mid)) l = mid + 1;
            else r = mid;
        }

        return (l - 1) * (l - 1);
    }
};
*/