#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    vector<pii> e;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        e.emplace_back(l[i], -1);
        e.emplace_back(r[i], 1);
    }
    sort(e.begin(), e.end());
    ll ans = 0;
    int k = 0;
    for (auto [_, v] : e) {
        if (v == -1) {
            ans += k++;
        }
        else k--;
    }
    cout << ans << "\n";
    return 0;
}