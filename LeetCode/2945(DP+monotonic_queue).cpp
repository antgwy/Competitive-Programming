class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n = (int)nums.size();
        vector<long long> sum(n + 1), lst(n + 1);
        vector<int> dp(n + 1), q(n + 1);
        int l = 0, r = 0;
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1] + nums[i-1];
            while (l < r && sum[q[l+1]] + lst[q[l+1]] <= sum[i]) l++;
            dp[i] = dp[q[l]] + 1;
            lst[i] = sum[i] - sum[q[l]];
            while (l <= r && sum[q[r]] + lst[q[r]] >= sum[i] + lst[i]) r--;
            q[++r] = i;
        }
        return dp[n];
    }
};