class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        const int INF = INT_MAX;
        vector<int> dp(n, INF);
        for (int i = 0; i < n; i++) {
            *lower_bound(dp.begin(), dp.begin() + n, nums[i]) = nums[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (dp[i] != INF);
        }
        return ans;
    }
};