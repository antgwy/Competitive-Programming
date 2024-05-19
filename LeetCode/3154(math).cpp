using ll = long long;

class Solution {
public:
    int waysToReachStair(int k) {
        const int M = 31;
        ll C[M][M];
        for (int i = 0; i < M; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
        k--;
        ll ans = 0;
        for (int i = 0; i < 30; i++) {
            int mx = (1 << i) - 1;
            if (k >= mx - (i + 1) && k <= mx) 
                ans += C[i+1][mx-k];
        }
        return ans;
    }
};
/*
using ll = long long;

class Solution {
public:
    int waysToReachStair(int k) {
        map<array<int, 3>, ll> memo;
        function<ll(int, int, int)> dp = [&](int i, int jump, int down) {
            auto key = array<int, 3>{i, jump, down};
            if (memo.count(key)) return memo[key];
            ll ret = 0;
            if (i == k) ret++;
            if (i + (1 << jump) <= k + 1) {
                ret += dp(i + (1 << jump), jump + 1, 0);
            }
            if (!down && i >= 1) {
                ret += dp(i - 1, jump, 1);
            }
            memo[key] = ret;
            return ret;
        };
        return dp(1, 0, 0);
    }
};
*/