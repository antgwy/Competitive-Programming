using ll = long long;

class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size(), m = andValues.size();
        unordered_map<ll, int> dp;
        
        auto dfs = [&](auto &&self, int i, int j, int andv) -> int { 
            if (m - j > n - i) return INT_MAX / 2;
            if (j == m) return i == n ? 0 : INT_MAX / 2;
            andv &= nums[i];
            if (andv < andValues[j]) return INT_MAX / 2;
            ll mask = (ll) i << 36 | (ll) j << 32 | andv;
            if (dp.contains(mask)) return dp[mask];
            int res = self(self, i + 1, j, andv);
            if (andv == andValues[j]) {
                res = min(res, self(self, i + 1, j + 1, -1) + nums[i]);
            }
            return dp[mask] = res;
        };

        int ans = dfs(dfs, 0, 0, -1);
        return ans < INT_MAX / 2 ? ans : -1;
    }
};