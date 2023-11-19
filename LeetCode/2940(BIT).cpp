// [x, y](x <= y): h[x] < h[t] && y < t，一维排序，二维区间最小值
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int m = queries.size();

        const int INF = 0x3f3f3f3f;
        int tr[n + 1];
        memset(tr, 0x3f, sizeof(tr));

        function<int(int)> lowbit = [&](int x) -> int { return x & -x; };
        auto update = [&](int pos, int val) {
            for (; pos <= n; pos += lowbit(pos))
                tr[pos] = min(tr[pos], val);
        };
        auto ask = [&](int pos) {
            int ret = INF;
            for (; pos; pos -= lowbit(pos)) ret = min(ret, tr[pos]);
            return ret;
        };

        vector<array<int, 3> > vec;
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            auto q1 = queries[i][0], q2 = queries[i][1];
            int a = min(q1, q2), b = max(q1, q2);
            if (a == b || heights[a] < heights[b]) ans[i] = b;
            else vec.push_back({-heights[a] - 1, i, b});
            // 确保一维 <
        }
        for (int i = 0; i < n; ++i) vec.push_back({-heights[i], -1, i});
        sort(vec.begin(), vec.end());
        for (auto &arr : vec) {
            int op = arr[1], idx = arr[2];
            if (op == -1) update(n - idx, idx);
            else {
                ans[op] = ask(n - idx - 1); // 确保二维 <
                if (ans[op] == INF) ans[op] = -1;
            }
        }
        return ans;
    }
};