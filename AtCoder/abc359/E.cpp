#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pii> sta;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        int cnt = 1;
        while (!sta.empty() && h >= sta.back().first) {
            auto [x, y] = sta.back();
            ans -= 1ll * x * y;
            cnt += y;
            sta.pop_back();
        }
        ans += 1ll * h * cnt;
        sta.emplace_back(h, cnt);
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}