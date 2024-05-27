using ll = long long;

struct Info {
    ll f00, f01, f10, f11;
    Info(int x = 0) : f00(0), f01(0), f10(0), f11(max(0, x)) {}
};

Info merge(const Info &a, const Info &b) {
    Info res;
    res.f00 = max(a.f00 + b.f10, a.f01 + b.f00);
    res.f01 = max(a.f00 + b.f11, a.f01 + b.f01);
    res.f10 = max(a.f10 + b.f10, a.f11 + b.f00);
    res.f11 = max(a.f10 + b.f11, a.f11 + b.f01);
    return res;
}

struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree(int n) : n(n), info(4 * n) {};
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        auto build = [&](auto &&self, int p, int l, int r) {
            if (r - l == 1) {
                info[p] = Info(init_[l]);
                return;
            }
            int mid = (l + r) / 2;
            self(self, 2 * p, l, mid);
            self(self, 2 * p + 1, mid, r);
            pull(p);
        };
        build(build, 1, 0, n);
    }
    void pull(int p) {
        info[p] = merge(info[2*p], info[2*p+1]);
    }
    void modify(int p, int l, int r, int pos, int v) {
        if (r - l == 1) {
            info[p] = Info(v);
            return;
        }
        int mid = (l + r) / 2;
        if (pos < mid) {
            modify(2 * p, l, mid, pos, v);
        } else {
            modify(2 * p + 1, mid, r, pos, v);
        }
        pull(p);
    }
    void modify(int pos, int v) {
        modify(1, 0, n, pos, v);
    }
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int mid = (l + r) / 2;
        return merge(query(2 * p, l, mid, x, y), query(2 * p + 1, mid, r, x, y));
    }
    Info query(int l, int r) {
        return query(1, 0, n, l, r);
    }
};

class Solution {
    const ll MOD = 1E9 + 7;
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree tr(n);      
        tr.init(nums);
        ll ans = 0;
        for (auto& q : queries) {
            tr.modify(q[0], q[1]);
            (ans += tr.query(0, n).f11) %= MOD;
        }
        return ans;
    }
};