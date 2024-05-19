#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return b[i] < b[j];
    });

    ll ans = 0;
    vector<ll> profit(n + 1);
    for (int i = 0; i < n; i++) {
        profit[i+1] = profit[i] + max(0, b[p[i]] - a[p[i]]);
    }
    ll sum = 0;
    priority_queue<int> pq;
    if (k == 0) ans = profit[n];
    for (int i = n - 1; i; i--) {
        pq.push(a[p[i]]);
        sum += a[p[i]];
        while ((int)pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
        if ((int)pq.size() == k) {
            ans = max(ans, profit[i] - sum);
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}