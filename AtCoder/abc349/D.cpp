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
    vector<pll> ans;
    while (L < R) {
        ll i = 0;
        while (L % (1LL << (i + 1)) == 0 && L + (1LL << (i + 1)) <= R) {
            i++;
        }
        ans.push_back({L, L + (1LL << i)});
        L += (1LL << i);
    }
    cout << ans.size() << "\n";
    for (auto &p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}