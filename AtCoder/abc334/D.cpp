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
    vector<int> r(n);
    vector<ll> sum(n + 1);
    for (int &e : r) cin >> e;
    sort(r.begin(), r.end());
    for (int i = 1; i <= n; ++i) sum[i] = sum[i-1] + 1ll * r[i-1];
    while (q--) {
        ll x;
        cin >> x;
        cout << upper_bound(sum.begin() + 1, sum.end(), x) - sum.begin() - 1 << "\n";
    }
    return 0;
}