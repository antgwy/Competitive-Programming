#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for (int i = 0; i < n; ++i) {
        pq.push(a[i]);
    }

    ll cost = 0, add = 0;

    while (k > 0) {
        auto p = pq.top();
        pq.pop();

        int buy = min(k, m);
        cost += (p + add) * buy;

        k -= buy;
        add += buy;
    }

    cout << cost << "\n";
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
