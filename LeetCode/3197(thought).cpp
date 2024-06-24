class Solution {
public:
    int minimumSum(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        auto get = [&](int nl, int nr, int ml, int mr) {
            vector<int> a(2, 31), b(2, 0);
            for (int i = nl; i <= nr; i++) {
                for (int j = ml; j <= mr; j++) {
                    if (g[i][j]) {
                        a[0] = min(a[0], i);
                        a[1] = min(a[1], j);
                        b[0] = max(b[0], i);
                        b[1] = max(b[1], j);
                    }
                }
            }
            return (b[0] - a[0] + 1) * (b[1] - a[1] + 1);
        };

        int ans = n * m;
        for (int i = 0; i + 1 < n; i++) {
            for (int j = i + 1; j + 1 < n; j++) {
                ans = min(ans, get(0, i, 0, m - 1) + get(i + 1, j, 0, m - 1) + get(j + 1, n - 1, 0, m - 1));
            }
        } 

        for (int i = 0; i + 1 < m; i++) {
            for (int j = i + 1; j + 1 < m; j++) {
                ans = min(ans, get(0, n - 1, 0, i) + get(0, n - 1, i + 1, j) + get(0, n - 1, j + 1, m - 1));
            }
        }  

        for (int i = 0; i + 1 < n; i++) { 
            for (int j = 0; j + 1 < m; j++) {
                ans = min(ans, get(0, i, 0, j) + get(0, i, j + 1, m - 1) + get(i + 1, n - 1, 0, m - 1));
                ans = min(ans, get(0, i, 0, m - 1) + get(i + 1, n - 1, 0, j) + get(i + 1, n - 1, j + 1, m - 1));
                ans = min(ans, get(0, i, 0, j) + get(i + 1, n - 1, 0, j) + get(0, n - 1, j + 1, m - 1));
                ans = min(ans, get(0, n - 1, 0, j) + get(0, i, j + 1, m - 1) + get(i + 1, n - 1, j + 1, m - 1));
            }
        }

        return ans;
    }
};
/*
class Solution {
public:
    int minimumSum(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        auto get = [&](int nl, int nr, int ml, int mr) {
            vector<int> a(2, 31), b(2, 0);
            for (int i = nl; i <= nr; i++) {
                for (int j = ml; j <= mr; j++) {
                    if (g[i][j]) {
                        a[0] = min(a[0], i);
                        a[1] = min(a[1], j);
                        b[0] = max(b[0], i);
                        b[1] = max(b[1], j);
                    }
                }
            }
            return (b[0] - a[0] + 1) * (b[1] - a[1] + 1);
        };
        auto get2 = [&](int nl, int nr, int ml, int mr) {
            int res = INT_MAX;
            for (int i = nl; i < nr; i++) {
                res = min(res, get(nl, i, ml, mr) + get(i + 1, nr, ml, mr));
                res = min(res, get(nl, i, ml, mr) + get(i + 1, nr, ml, mr));
            }
            for (int i = ml; i < mr; i++) {
                res = min(res, get(nl, nr, ml, i) + get(nl, nr, i + 1, mr));
                res = min(res, get(nl, nr, ml, i) + get(nl, nr, i + 1, mr));
            }
            return res;
        };
        int ans = INT_MAX;        
        for (int i = 1; i < n; i++) {
            ans = min(ans, get(0, i - 1, 0, m - 1) + get2(i, n - 1, 0, m - 1));
            ans = min(ans, get2(0, i - 1, 0, m - 1) + get(i, n - 1, 0, m - 1));
        }
        for (int i = 1; i < m; i++) {
            ans = min(ans, get(0, n - 1, 0, i - 1) + get2(0, n - 1, i, m - 1));
            ans = min(ans, get2(0, n - 1, 0, i - 1) + get(0, n - 1, i, m - 1));
        }
        return ans;
    }
};
*/