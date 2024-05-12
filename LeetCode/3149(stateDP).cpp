class Solution {
public:
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(1 << n, vector<int>(n, 1e9));
        vector<vector<int> > nxt(1 << n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            dp[(1<<n)-1][i] = abs(i - nums[0]);
        for (int mask = (1 << n) - 3; mask > 0; mask -= 2) {
            for (int i = 0; i < n; i++) {
                if (!(mask >> i & 1)) continue;
                for (int j = 1; j < n; j++) {
                    if ((mask >> j & 1) || j == i) continue;
                    auto v = dp[mask|(1<<j)][j] + abs(i - nums[j]);
                    if (dp[mask][i] > v) {
                        dp[mask][i] = v;
                        nxt[mask][i] = j;
                    }
                }
            }
        }

        int s = 0, ptr = 0;
        vector<int> p;
        while (ptr >= 0) {
            p.push_back(ptr);
            s |= 1 << ptr;
            ptr = nxt[s][ptr];
        }
        return p;
    }
};