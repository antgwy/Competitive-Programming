#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

template<typename T>
struct fenwick {
    int n;
    vector<T> a;
    fenwick(int n_ = 0) { init(n_); }
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
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i-1];
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> ans(m);
    fenwick<ll> tr(m);
    for (int i = 0; i < n; i++) {
        ans[0] += tr.sum(m) - tr.sum(a[i] + 1);
        tr.add(a[i], 1);
    }

    vector<vector<int> > pos(m);
    for (int i = 0; i < n; i++) {
        pos[a[i]].push_back(i + 1);
    }

    for (int i = 0; i < m - 1; i++) {
        int k = m - 1 - i;
        int t = pos[k].size();
        ans[i+1] = ans[i];
        for (int j = 0; j < t; j++) {
            int id = pos[k][j];
            ans[i+1] += (2 * id - n - 2);
            ans[i+1] += (t - 2 * j);
        }
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}