class Solution {
    typedef long long ll;
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.insert(nums.begin(), 0);
        vector<ll> sum(n + 1);
        for (int i = 1; i <= n; ++i) sum[i] = sum[i-1] + nums[i];
        auto check = [&](ll x) {
            for (int l = 1, r; l + x - 1 <= n; ++l) {
                r = l + x - 1;
                ll mid = (l + r) >> 1;
                if (1ll * nums[mid] * (mid - l + 1) - (sum[mid] - sum[l-1]) + (sum[r] - sum[mid]) - 1ll * nums[mid] * (r - mid) <= k)
                    return true;
            }
            return false;
        };
        int l = 1, r = n + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) l = mid + 1;
            else r = mid;
        }
        return l - 1;
    }
};