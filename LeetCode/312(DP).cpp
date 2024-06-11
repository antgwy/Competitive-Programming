class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int> > f(n, vector<int>(n, 0));
        for (int r = 2; r < n; r++) {
            for (int l = r - 2; l >= 0; l--) {
                for (int k = l + 1; k < r; k++) {
                    f[l][r] = max(f[l][r], f[l][k] + f[k][r] + nums[l] * nums[k] * nums[r]);
                }
            }
        }
        return f[0][n-1];
    }
};
/*
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int> > f(n, vector<int>(n, -1));

        auto dfs = [&](auto &&self, int l, int r) -> int {
            if (l + 1 >= r) return 0;
            if (f[l][r] != -1) return f[l][r];
            auto &ret = f[l][r];
            for (int k = l + 1; k < r; k++) {
                ret = max(ret, self(self, l, k) + self(self, k, r) + nums[l] * nums[k] * nums[r]);
            }
            return ret;
        };

        return dfs(dfs, 0, n - 1);
    }
};
*/