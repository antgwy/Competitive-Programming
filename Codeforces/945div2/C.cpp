#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<pii> v[2];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        v[i&1].emplace_back(p[i], i);
    }
    vector<int> q(n + 1);
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    if (v[0][0].first != 1) swap(v[0], v[1]);
    for (int i = 0; i < n / 2; i++) q[v[0][i].second] = n / 2 - i;
    for (int i = 0; i < n / 2; i++) q[v[1][i].second] = n - i;
    for (int i = 1; i <= n; i++)
        cout << q[i] << " \n"[i == n];
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