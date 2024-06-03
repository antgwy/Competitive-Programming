#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;
    Fenwick(int n_ = 0) { init(n_); }
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i-1] = a[i-1] + v;
        }
    }
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i-= i & -i) {
            ans = ans + a[i-1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << __lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x+i-1] <= k) {
                x += i;
                cur = cur + a[x-1];
            }
        }
        return x;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    ll k;
    cin >> q >> k;

    vector<int> o(q);
    vector<ll> x(q);
    for (int i = 0; i < q; i++) {
        cin >> o[i] >> x[i];
    }
    auto v = x;
    sort(v.begin(), v.end());
    
    Fenwick<int> fen(q);
    set<ll> s;
    set<ll> sl;

    for (int i = 0; i < q; i++) {
        int vx = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
        if (o[i] == 1) {
            if (s.count(x[i])) {
                sl.erase(x[i]);
                auto it = s.find(x[i]);
                it = s.erase(it);
                if (it != s.end() && (it == s.begin() || *it - *prev(it) > k)) {
                    sl.insert(*it);
                }
                fen.add(vx, -1);
            }
            else {
                auto it = s.insert(x[i]).first;
                auto r = next(it);
                if (r != s.end() && *r - x[i] <= k) {
                    sl.erase(*r);
                }
                if (it == s.begin() || x[i] - *prev(it) > k) {
                    sl.insert(x[i]);
                }
                fen.add(vx, 1);
            }
        }
        else {
            int l, r;
            auto it = sl.upper_bound(x[i]);
            if (it == sl.end()) {
                r = q;
            }
            else {
                r = lower_bound(v.begin(), v.end(), *it) - v.begin();
            }

            it--;
            l = lower_bound(v.begin(), v.end(), *it) - v.begin();
            int ans = fen.rangeSum(l, r);
            cout << ans << "\n";
        }
    }
    return 0;
}