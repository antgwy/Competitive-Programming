class BIT {
private:
    vector<int> tr;
    int n;

public:
    BIT(int x): n(x), tr(x + 1) {}

    static int lowbit(int x) { return x & -x; }    

    int query(int x) {
        int res = 0;
        for (; x; x -= lowbit(x))
            res += tr[x];
        return res;
    }

    void update(int x, int t) {
        for (; x <= n; x += lowbit(x))
            tr[x] += t;
    }
};

class Solution {
public:
    int reversePairs(vector<int>& record) {
        int n = record.size();
        vector<int> tmp = record;
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        for (int &num : record) {
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
        }
        BIT bit(n);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans += bit.query(record[i] - 1);
            bit.update(record[i], 1);
        }
        return ans;
    }
};