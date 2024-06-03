class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int> > st(__lg(n) + 1, vector<int>(n));
        for (int i = 0; i < n; i++) st[0][i] = nums[i];
        for (int i = 1; i <= __lg(n); i++) {
            for (int j = 0; j < n - (1 << i) + 1; j++) {
                st[i][j] = st[i-1][j] & st[i-1][j+(1<<(i-1))];
            }
        }
        auto query = [&](int l, int r) {
            assert(l <= r);
            int lg = __lg(r - l + 1);
            return st[lg][l] & st[lg][r-(1<<lg)+1];
        };
        
        if (n == 1) return abs(nums[0] - k);
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= k) {
                ans = min(ans, k - nums[i]);
                continue;
            }
            int l = i, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (query(i, mid) >= k) l = mid + 1;
                else r = mid;
            }
            ans = min(ans, query(i, l - 1) - k);
            if (query(i, n - 1) <= k) {
                int l = i, r = n;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (query(i, mid) <= k) r = mid;
                    else l = mid + 1;
                }
                ans = min(ans, k - query(i, r));
            }
        }
        return ans;
    }
};
/*
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        set<int> s;
        for (int x : nums) {
            set<int> ss;
            ss.insert(x);
            for (int y : s) {
                ss.insert(x & y);
            }
            swap(s, ss);
            for (int y : s) {
                ans = min(ans, abs(y - k));
            }
        }
        return ans;
    }
};
*/