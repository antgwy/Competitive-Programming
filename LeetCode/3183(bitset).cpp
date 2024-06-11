class Solution {
public:
    int maxTotalReward(vector<int>& rewards) {
        ranges::sort(rewards);
        rewards.erase(unique(rewards.begin(), rewards.end()), rewards.end());

        const int N = 1e5;
        bitset<N> f{1};
        for (int r : rewards) {
            int shift = N - r;
            // >= r 位置置 0
            f |= f << shift >> shift << r;
        }
        for (int i = rewards.back() * 2 - 1; ; i--) {
            if (f.test(i)) return i;
        }
    }
};