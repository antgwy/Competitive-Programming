using ll = long long;

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        auto check = [&](ll m) {
            ll cnt = 0;
            for (int i = 1; i < (1 << n); i++) {
                ll res = 1;
                for (int j = 0; j < n; j++) {
                    if (i >> j & 1) {
                        res = lcm(res, coins[j]);
                        if (res > m) break;
                    }
                }
                cnt += (__builtin_popcount(i) % 2 ? m / res : -m / res);
            }
            return cnt >= k;
        };

        ll left = 0, right = 1ll * ranges::min(coins) * k + 1;
        while (left < right) {
            ll mid = (left + right) >> 1;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};