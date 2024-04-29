#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<ll, ll> pll;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll L, R;
    cin >> L >> R;
    auto f = [&](auto &self, ll l, ll r, ll L, ll R) -> vector<pll> {
        if (L <= l && r <= R) return {{l, r}};
        ll mid = (l + r) >> 1;
        vector<pll> res;
        if (R <= mid) {
            auto left = self(self, l, mid, L, R);
            res.insert(res.end(), left.begin(), left.end());
        }
        else if (mid <= L) {
            auto right = self(self, mid, r, L, R);
            res.insert(res.end(), right.begin(), right.end());
        }
        else {
            auto left = self(self, l, mid, L, R);
            auto right = self(self, mid, r, L, R);
            res.insert(res.end(), left.begin(), left.end());
            res.insert(res.end(), right.begin(), right.end());
        }
        return res;
    };
    auto ans = f(f, 0, 1ll << 60, L, R);
    cout << ans.size() << "\n";
    for (auto &p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}