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
    int h, w, m;
    cin >> h >> w >> m;
    ll hc = h, wc = w;
    vector<bool> f(h), g(w);
    vector<int> t(m), a(m), x(m);  
    for (int i = 0; i < m; ++i) {
        cin >> t[i] >> a[i] >> x[i];
        a[i]--;
    }
    map<int, ll> cnt;
    for (int i = m - 1; i >= 0; --i) {
        if (t[i] == 1) {
            if (!f[a[i]]) {
                f[a[i]] = true;
                hc--;
                if (wc) cnt[x[i]] += wc;
            }
        }
        else {
            if (!g[a[i]]) {
                g[a[i]] = true;
                wc--;
                if (hc) cnt[x[i]] += hc;
            }
        }
    }
    if (hc && wc) cnt[0] += 1ll * hc * wc;
    cout << cnt.size() << "\n";
    for (auto &[c1, c2] : cnt) {
        cout << c1 << " " << c2 << "\n";
    }
    return 0;
}