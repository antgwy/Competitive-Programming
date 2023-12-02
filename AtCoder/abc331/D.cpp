#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<string> S(n);
    vector<vector<int> > p(n + 1, vector<int>(n + 1));
    for (auto &s : S) cin >> s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            p[i][j] += S[i-1][j-1] == 'B';
            p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }
    function<ll(int, int)> f = [&](int h, int w) {
        if (h <= n and w <= n) return 1ll * p[h][w];
        int hq = h / n, hr = h % n;
        int wq = w / n, wr = w % n;
        ll ret = 0;
        ret += f(n, n) * hq * wq;
        ret += f(hr, n) * wq;
        ret += f(n, wr) * hq;
        ret += f(hr, wr);
        return ret;
    };
    auto g = [&](int a, int b, int c, int d) {
        return f(c, d) - f(a, d) - f(c, b) + f(a, b);
    };
    int a, b, c, d;
    while (q--) {
        cin >> a >> b >> c >> d;
        int x = (c - a + 1) / n;
        int y = (d - b + 1) / n;
        ll ans = g(a, b, c + 1, d + 1);
        cout << ans << "\n";
    }
    return 0;
}