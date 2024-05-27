#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    map<pii, int> bi[3];
    map<array<int, 3>, int> tri;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pii x[3];
    ll ans = 0;
    for (int i = 0; i < n - 2; i++) {
        x[0] = {a[i+1], a[i+2]};
        x[1] = {a[i], a[i+2]};
        x[2] = {a[i], a[i+1]};
        array<int, 3> v = {a[i], a[i+1], a[i+2]};
        tri[v]++; 
        for (int i = 0; i < 3; i++) {
            bi[i][x[i]]++;
            ans += (bi[i][x[i]] - tri[v]);
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