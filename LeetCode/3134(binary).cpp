using ll = long long;

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        ll k = (1ll * n * (n + 1) / 2 + 1) / 2;
        
        auto check = [&](int upp) {
            ll cnt = 0;
            int l = 0;
            unordered_map<int, int> f;
            for (int r = 0; r < n; r++) {
                f[nums[r]]++;
                while (f.size() > upp) {
                    int out = nums[l++];
                    if (--f[out] == 0) f.erase(out);
                }
                cnt += r - l + 1;
                if (cnt >= k) return true;
            }
            return false;
        };

        int left = 0, right = n + 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};