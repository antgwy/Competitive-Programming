#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

const int B[] = {131, 13331};
const int P[] = {998244353, 1000000007};
const int C = 2;
struct Hash {
    vector<int> h[C], pw[C];
    Hash() {}
    Hash(string s) {
        int n = s.size();
        init(s, n);
    }
    void init(string s, int n) {
        for (int i = 0; i < C; i++) {
            h[i].resize(n + 1);
            pw[i].resize(n + 1);
            h[i][0] = 1; pw[i][0] = 1;
        }
        for (int i = 0; i < C; i++) {
            for (int j = 1; j <= n; j++) {
                h[i][j] = (1ll * h[i][j-1] * B[i] + s[j-1]) % P[i];
                pw[i][j] = 1ll * pw[i][j-1] * B[i] % P[i];
            }
        }
    }
    auto get(int l, int r) {
        array<int, C> v{};
        if (l > r) return v;
        for (int i = 0; i < C; i++) {
            v[i] = (h[i][r] - 1ll * h[i][l-1] * pw[i][r-l+1]) % P[i];
            if (v[i] < 0) v[i] += P[i];
        }
        return v;
    }
    auto get(int l, int r, int d) {
        auto v = get(l, r);
        if (l > r) return v;
        for (int i = 0; i < C; i++) v[i] = 1ll * v[i] * pw[i][d] % P[i];
        return v;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string r = s;
    reverse(r.begin(), r.end());
    string a, b;
    for (int i = 0; i < n / k; i++) {
        a += string(k, '0' + ((i & 1) == 1));
        b += string(k, '0' + ((i & 1) != 1));
    }
    Hash ha(a), hb(b);
    Hash hs(s), hr(r);
    auto va = ha.get(1, n);
    auto vb = hb.get(1, n);
    if (hs.get(1, n) == va || hs.get(1, n) == vb) { cout << n << "\n"; return; }
    auto add = [&](auto v1, auto v2) {
        array<int, C> res;
        for (int i = 0; i < C; i++) {
            res[i] = (1ll * v1[i] + v2[i]) % P[i];
        }
        return res;
    };
    for (int i = 1; i < n; i++) {
        auto cur = add(hs.get(i + 1, n, i), hr.get(n - i + 1, n));
        if (cur == va || cur == vb) { cout << i << "\n"; return; }
    }
    cout << "-1\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}