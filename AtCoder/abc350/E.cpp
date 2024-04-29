#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    int a, x, y;
    cin >> n >> a >> x >> y;
    unordered_map<ll, double> f;
    f[0] = 0.0;
    auto dp = [&](auto self, ll m) -> double {
        if (f.count(m)) return f[m];
        auto &v = f[m];
        double cost = 0.0;
        for (int i = 2; i <= 6; ++i) {
            cost += self(self, m / i);
        }
        cost = cost / 5.0 + 1.2 * y; 
        v = min(self(self, m / a) + 1.0 * x, cost);
        return v;
    };
    cout << fixed << setprecision(7) << dp(dp, n) << "\n";
    return 0;
}