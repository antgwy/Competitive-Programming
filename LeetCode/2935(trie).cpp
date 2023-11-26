// https://leetcode.com/contest/weekly-contest-371/problems/maximum-strong-pair-xor-ii/
struct Trie{
    struct Node {
        Node *son[2];
        int cnt = 0;
    };
    Node *root;
    Trie() {
        root = new Node();
    }
    void add(int x, int weight) {
        auto cur = root;
        cur->cnt += weight;
        for (int i = 19; ~i; --i) {
            int ch = x >> i & 1;
            if (cur->son[ch] == nullptr) cur->son[ch] = new Node();
            cur = cur->son[ch];
            cur->cnt += weight;
        }
    }
    int getmax(int x) {
        auto cur = root;
        int res = 0;
        for (int i = 19; ~i; --i) {
            int ch = x >> i & 1;
            if (cur->son[ch ^ 1] != nullptr && cur->son[ch ^ 1]->cnt) {
                res |= 1 << i;
                cur = cur->son[ch ^ 1];
            }
            else cur = cur->son[ch];
        }
        return res;
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        Trie trie;
        int ans = 0, l = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            trie.add(nums[i], 1);
            while (nums[l] * 2 < nums[i]) {
                trie.add(nums[l++], -1);
            }
            ans = max(ans, trie.getmax(nums[i]));
        }
        return ans;
    }
};