/*
https://atcoder.jp/contests/abc325/tasks/abc325_d
if there is an unprinted product within the range of the printer at 
t, then print on the one with the earliest exit time among them.
If at some time t, there is no printable product (i.e. there is no 
unprinted product within the range of the printer), then let t←t′, where 
t′ is the first time on which a product enters the range of the printer later than t.
*/
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<ll, ll> > v;
    for (int i = 1; i <= n; ++i) {
        ll t, d;
        cin >> t >> d;
        v.emplace_back(t, t + d);
    }
    sort(v.begin(), v.end());
    priority_queue<ll, vector<ll>, greater<> > pq;
    int ans = 0, it = 0;
    for (ll i = 0; ; ++i) {
        if (pq.empty()) {
            if (it == n) break;
            i = v[it].first;
        }
        while (it < n && v[it].first == i) {
            pq.push(v[it++].second);
        }
        while (!pq.empty() && pq.top() < i) pq.pop();
        if (!pq.empty()) {
            pq.pop();
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}
