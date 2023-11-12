// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
class Trie{
public:
    const static int M = 3e6;
    int tr[M][2], tot = 0;
    void init() {
        memset(tr, 0, sizeof(tr));
    }
    void insert(int x){
        int p = 0;
        for(int i = 30; ~i; --i) {
            int ch = (x >> i) & 1;
            if(!tr[p][ch]) tr[p][ch] = ++tot;
            p = tr[p][ch];
        }
    }
    int getmax(int num) {
        int res = 0, p = 0;
        for (int i = 30; ~i; --i) {
            int ch = (num >> i) & 1;
            if (tr[p][ch ^ 1]) {
                res |= 1 << i;
                p = tr[p][ch ^ 1];
            }
            else p = tr[p][ch];
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        Trie trie;
        trie.init();
        for (auto it : nums) {
            trie.insert(it);
        }
        for (auto it : nums) {
            res = max(res, trie.getmax(it));
            cout << res << "\n";
        }
        return res;
    }
};