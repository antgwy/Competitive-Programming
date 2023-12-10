class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = (int)nums.size();
        unordered_map<int, int> lst;
        for (int i = 0; i < n; ++i) {
            lst[nums[i]] = i;
        }
        int ans = 1, maxr = -1;
        for (int i = 0; i < n - 1; ++i) {
            maxr = max(maxr, lst[nums[i]]);
            if (maxr == i) ans = ans * 2 % MOD;
        }
        return ans;
    }
};